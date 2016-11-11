#include "Ent.h"
#include "PhysicsController.h"
#include "Sphere.h"
#include "PhysicsCamera.h"
#include "Box.h"
#include "Cylinder.h"
#include "Steerable3DController.h"
#include "Ground.h"
#include "Content.h"
#include <btBulletDynamicsCommon.h>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include <gtx/norm.hpp>
#include "VectorDrawer.h"
#include "Utils.h"

using namespace BGE;

Ent::Ent(void)
{
}

Ent::~Ent(void)
{
}

shared_ptr<PhysicsController> cyl;
std::shared_ptr<GameComponent> station;

bool Ent::Initialise() 
{	
	physicsFactory->CreateGroundPhysics();
	physicsFactory->CreateCameraPhysics();	


	//We're gonna build a wall
	int i = 0,
		j = 0;
	int k = 5,
		l = 2;

	shared_ptr<PhysicsController> box[10][10];

	for (j = 0; j < l; ++j) {
		for (i = 0; i < k; ++i) {
			box[i][j] = physicsFactory->CreateBox(5, 5, 5, glm::vec3(5 * i, 5 * j, 0), glm::quat());
		}
	}

	if (!Game::Initialise()) {
		return false;
	}

	camera->transform->position = glm::vec3(0,10, 20);
	
	return true;
}

void BGE::Ent::Update(float timeDelta)
{
	cyl->rigidBody->applyTorque(GLToBtVector(glm::vec3(0.0f,0.0f,1.0f)));

	Game::Update(timeDelta);
}

void BGE::Ent::Cleanup()
{
	Game::Cleanup();
}
