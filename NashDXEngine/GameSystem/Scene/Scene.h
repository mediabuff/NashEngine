////////////////////////////////////////////////////////////////////////////////
// Filename: Scene.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _Scene_H_
#define _Scene_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "../Direct3DManager/D3DManager.h"
#include "../InputManager/InputManager.h"
#include "../Shader/ShaderManager.h"
#include "../Texture/TextureManager.h"
#include "../Texture/RenderTexture.h"
#include "../TimerManager/TimerManager.h"
#include "../UI/UserInterface.h"
#include "../Camera/Camera.h"
#include "Light/Light.h"
#include "Position/Position.h"
#include "Terrain/Frustum/Frustum.h"
#include "Model/SkyDome.h"
#include "Model/Model.h"
#include "Terrain/Terrain.h"
#include "Terrain/Water/Water.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: Scene
////////////////////////////////////////////////////////////////////////////////
class Scene
{
public:
	Scene();
	Scene(const Scene&);
	~Scene();

	bool Initialize(HWND, int, int, float);
	void Shutdown();
	bool Frame(ShaderManager*, float, int);
	bool isHeightLocked();

private:
	void HandleMovementInput(InputManager*, float);
	void RenderRefractionToTexture();
	void RenderReflectionToTexture();
	bool Render(ShaderManager*);

private:
	UserInterface* m_UserInterface;
	Camera* m_Camera;
	Position* m_Position;
	Frustum* m_Frustum;
	SkyDome* m_SkyDome;
	Light* m_Light;
	Terrain* m_Terrain;
	Water* m_Water;
	Model* m_TreeModel;
	RenderTexture *m_RefractionTexture, *m_ReflectionTexture;


	bool m_displayUI, m_wireFrame, m_cellLines, m_heightLocked;
	XMFLOAT4 sandColor, grassColor;
};

#endif