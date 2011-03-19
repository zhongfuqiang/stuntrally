#ifndef _FolowCamera_h_
#define _FolowCamera_h_

#include <Ogre.h>
#include <vector>
using namespace Ogre;
using namespace std;


enum CamTypes
{
	CAM_Follow = 0,	//  0 Follow - car rotY & pos from behind car, smooth
	CAM_Free,		//  1 Free   - free rot, pos from car
	CAM_Arena,		//  2 Arena  - free pos & rot, fly
	CAM_Car			//  3 Car    - car pos & rot, full
};

const char CAM_Str[4][10] = {"Follow", "Free", "Arena", "Car"};


class CameraAngle
{
public:
	CamTypes  mType;  String  mName;
	Real  mDist, mSpeed, mSpeedRot;
	Radian  mYaw, mPitch;
	Vector3 mOffset;
	int mMain, mHideGlass;

	CameraAngle();
};



class FollowCamera
{
public:
	class Camera*  mCamera;

	const class Node  *mGoalNode;
	Vector3  mLook;
	CameraAngle  ca;
	bool  first;


	FollowCamera(Camera* cam);
	~FollowCamera();

	void  update(Real time);
	void  updInfo(Real time = 0);	Real fMoveTime;
	void  Move( bool mbLeft, bool mbRight, bool mbMiddle, bool shift, Real mx, Real my, Real mz );


	//  Camera Angles
	int  miCount, miCurrent;
	std::vector<CameraAngle>  mCameraAngles;

	bool  loadCameras();  void saveCamera();
	void  updAngle(),  incCur(int dir);
	void  Next(bool bPrev = false, bool bMainOnly = false);
	void  setCamera(int ang);
	
	OverlayElement  *ovInfo,*ovName;
};

#endif