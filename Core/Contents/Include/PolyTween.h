/*
 *  PolyTween.h
 *  Poly
 *
 *  Created by Ivan Safrin on 7/7/08.
 *  Copyright 2008 Ivan Safrin. All rights reserved.
 *
 */

// @package BasicTypes

#pragma once
#include "PolyString.h"
#include "PolyGlobals.h"
#include "PolyEventDispatcher.h"
#include "PolyCoreServices.h"
#include "PolyBezierCurve.h"
#include "PolyQuaternionCurve.h"

namespace Polycode {
	
	class Timer;
	
	/**
	* Tween animation class. This class lets you tween a floating point value over a period of time with different easing types.
	*/	
	class _PolyExport Tween : public EventDispatcher {
	public:
		
		/**
		* Constructor.
		* @param target Pointer to the Number to tween
		* @param easeType Easing type. See the static members of this class for the different types of easing you can use.
		* @param startVal Starting value of the number at tween's start.
		* @param endVal The value to tween the number to.
		* @param time The duration of the tween.
		* @param repeat If true, this tween will repeat over and over.
		*/
		Tween(Number *target, int easeType, Number startVal, Number endVal, Number time, bool repeat=false);
		~Tween();
		
		void handleEvent(Event *event);
		Number interpolateTween();
		virtual void updateCustomTween() {}
		void doOnComplete();
		
		/**
		* Pauses and resumes the tween.
		* @param pauseVal If true, pauses the tweem, if false, resumes it.
		*/
		void Pause(bool pauseVal);

		/**
		* Resets the tween to starting position.
		*/		
		void Reset();
		
		static const int EASE_NONE = 0;
		static const int EASE_IN_QUAD = 1;
		static const int EASE_OUT_QUAD = 2;
		static const int EASE_INOUT_QUAD = 3;
		static const int EASE_IN_CUBIC= 4;
		static const int EASE_OUT_CUBIC= 5;
		static const int EASE_INOUT_CUBIC= 6;
		static const int EASE_IN_QUART= 7;
		static const int EASE_OUT_QUART= 8;
		static const int EASE_INOUT_QUART= 9;
		static const int EASE_IN_QUINT= 10;
		static const int EASE_OUT_QUINT= 11;
		static const int EASE_INOUT_QUINT= 12;
		static const int EASE_IN_SINE= 13;
		static const int EASE_OUT_SINE= 14;
		static const int EASE_INOUT_SINE= 15;
		static const int EASE_IN_EXPO= 16;
		static const int EASE_OUT_EXPO= 17;
		static const int EASE_INOUT_EXPO= 18;
		static const int EASE_IN_CIRC= 19;
		static const int EASE_OUT_CIRC= 20;
		static const int EASE_INOUT_CIRC= 21;
		static const int EASE_IN_BOUNCE= 22;
		static const int EASE_OUT_BOUNCE = 23;
		static const int EASE_INOUT_BOUNCE = 24;	
		
		bool isComplete();
		bool repeat;
		
		/*
		* Set a speed multiplier for the tween
		* @param speed Speed multiplier.
		*/
		void setSpeed(Number speed);
		

	protected:
	
		
		int easeType;
		bool complete;
		Number endVal;
		Number cVal;
		Number startVal;
		Number actEndTime;
		Number endTime;
		Number *targetVal;
		Number localTargetVal;
		Number tweenTime;
		Timer *tweenTimer;
	};
	
	/**
	* Tweens a position along a bezier path. This class automatically animates a 3d position over a 3d bezier curve. You can use it for 2d curves as well, of course, just ignore the z!
	*/
	class _PolyExport BezierPathTween : public Tween {
		public:
			/**
			* Constructor.
			* @param target Target vector to animate.
			* @param curve The curve to animate along.
			* @param easeType Easing type (@see Tween)
			* @param time The duration of the tween.
			* @param repeat If true, this tween will repeat over and over.
			*/
			BezierPathTween(Vector3 *target, BezierCurve *curve, int easeType, Number time, bool repeat=false);
			
			~BezierPathTween();
			void updateCustomTween();

		protected:
			Number pathValue;
			Tween *pathTween;
			BezierCurve *curve;
			Vector3 *target;
	};
	
	class _PolyExport QuaternionTween : public Tween {
		public:
			QuaternionTween(Quaternion *target, BezierCurve *wCurve, BezierCurve *xCurve, BezierCurve *yCurve,
							BezierCurve *zCurve, int easeType, Number time, bool repeat=false);
			~QuaternionTween();
			void updateCustomTween();
		private:
			Number pathValue;
			Tween *pathTween;
			QuaternionCurve	*quatCurve;
			Quaternion *target;			
	};
	
}