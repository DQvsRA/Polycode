/*
 *  PolyParticle.h
 *  Poly
 *
 *  Created by Ivan Safrin on 7/18/08.
 *  Copyright 2008 Ivan Safrin. All rights reserved.
 *
 */
// @package Scene

#pragma once
#include "PolyString.h"
#include "PolyGlobals.h"
#include "PolySceneEntity.h"
#include "PolyScreenShape.h"
#include "PolyScenePrimitive.h"
#include "PolyCoreServices.h"


namespace Polycode {

	class _PolyExport Particle {
		public:
			Particle(int particleType, bool isScreenParticle, Material *material, Texture *texture, Mesh *particleMesh);
			~Particle();
			void Reset(bool continuious);
			
			void createSceneParticle(int particleType, Texture *texture, Mesh *particleMesh);
			void createScreenParticle(int particleType, Texture *texture, Mesh *particleMesh);
		
			Entity *particleBody;						
			
			Vector3 velVector;
			Vector3 dirVector;	
			Vector3 deviation;		
			Number life;
			Number lifespan;
			Number brightnessDeviation;
			Number perlinPosX;
			Number perlinPosY;
			Number perlinPosZ;
			
			static const int BILLBOARD_PARTICLE = 0;
			static const int MESH_PARTICLE = 1;
	};
}