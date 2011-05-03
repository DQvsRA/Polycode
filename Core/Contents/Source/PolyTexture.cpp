/*
 *  PolyTexture.cpp
 *  Poly
 *
 *  Created by Ivan Safrin on 3/13/08.
 *  Copyright 2008 Ivan Safrin. All rights reserved.
 *
 */

#include "PolyTexture.h"

using namespace Polycode;

Texture::Texture(unsigned int width, unsigned int height, char *textureData,bool clamp, int type) : Resource(Resource::RESOURCE_TEXTURE) {
	this->width = width;
	this->height = height;
	this->clamp = clamp;
	
	switch (type) {
		case Image::IMAGE_RGB:
			pixelSize = 3;
			break;
		case Image::IMAGE_RGBA:
			pixelSize = 4;
			break;			
		default:
			pixelSize = 3;			
			break;
	}
	
	this->textureData = (char*)malloc(width*height*pixelSize);
	if(textureData)
		memcpy(this->textureData, textureData, width*height*pixelSize);	
	else
		memset(this->textureData, 0, width*height*pixelSize);	
	scrollSpeedX = 0;
	scrollSpeedY = 0;
	scrollOffsetX = 0;
	scrollOffsetY = 0;
	resourcePath = "";
}

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}

Texture::~Texture(){
	free(textureData);
}

void Texture::setImageData(Image *data) {

	if(this->textureData)
		free(this->textureData);
	this->textureData = (char*)malloc(width*height*pixelSize);
	memcpy(this->textureData, data->getPixels(), width*height*pixelSize);
	setTextureData(data->getPixels());

}

Texture::Texture(Image *image) : Resource(Resource::RESOURCE_TEXTURE) {	
	pixelSize = 4;
	this->textureData = (char*)malloc(image->getWidth()*image->getHeight()*pixelSize);
	memcpy(this->textureData, image->getPixels(), image->getWidth()*image->getHeight()*pixelSize);	

}

void Texture::setResourcePath(String newPath) {
	resourcePath = newPath;
}

String Texture::getResourcePath() {
	return resourcePath;
}

void Texture::updateScroll(int elapsed) {
	Number ef = ((Number)(elapsed))/1000.0f;
	scrollOffsetX += scrollSpeedX*ef;
	scrollOffsetY += scrollSpeedY*ef;
}

Number Texture::getScrollOffsetX() {
	return scrollOffsetX;
}

Number Texture::getScrollOffsetY() {
	return scrollOffsetY;
}