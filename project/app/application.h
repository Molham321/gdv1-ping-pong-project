
#pragma once

#include "yoshix_fix_function.h"
#include "field.h"
#include "ball.h"
#include "bat.h"
#include "position.h"

#include <math.h>
#include <conio.h>


class CApplication : public gfx::IApplication
{
public:

	/* constructors &  */

	CApplication();
	virtual ~CApplication();

private:

	/* namespase for BHandle */

	using BHandle = gfx::BHandle;

private:

	/* A pointer to a YoshiX mesh, which represents a single cube */

	BHandle m_pCubeMesh;																	
	BHandle m_pBatMesh;						

	/* A pointer to a YoshiX mesh, which represents a single sphere */

	BHandle m_pBallMesh;																

	/* Bat coordination */

	SPosition m_BatPlayerOnePosition;														
	SPosition m_BatPlayerTowPosition;

	/* Ball coordination */

	SPosition m_BallPosition;																

	/* ball velocity on the x and y axis */

	SPosition m_BallSpeedPosition;															

	float const     m_BatMovementSpeedY;
	float			m_AngleY;
	float			m_GameBoard[CField::s_GameBoardWidth][CField::s_GameBoardHeight];		// Spielbrettmatrix

	bool            IsGameStarted;

private:

	/* this is used to create walls and bat */

	void CreateCube(BHandle* _ppMesh, float _EdgeLength);

	/* this is used to create ball */

	void CreateSphere(BHandle* _ppMesh, float _Radius);

	/* it is checked whether the ball position on the x and y axis has crossed a certain distance */

	bool CheckCollision(int _xPosition, int _yPosition);

private:

	virtual bool InternOnStartup();
	virtual bool InternOnShutdown();
	virtual bool InternOnCreateMeshes();
	virtual bool InternOnReleaseMeshes();
	virtual bool InternOnResize(int _Width, int _Height);
	virtual bool InternOnKeyEvent(unsigned int _Key, bool _IsKeyDown, bool _IsAltDown);
	virtual bool InternOnUpdate();
	virtual bool InternOnFrame();
};