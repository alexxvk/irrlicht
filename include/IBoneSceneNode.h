#ifndef __I_BONE_SCENE_NODE_H_INCLUDED__
#define __I_BONE_SCENE_NODE_H_INCLUDED__

// Used with SkinnedMesh and IAnimatedMeshSceneNode, for boned meshes

#include "ISceneNode.h"

namespace irr
{
namespace scene
{

	//! Enumeration for different bone animation modes
	enum E_BONE_ANIMATION_MODE
	{
		//! The bone is usually animated, unless it's parent is not animated
		EBAM_AUTOMATIC=0,

		//! The bone is animated by the skin, if it's parent is not animated
		//! then animation will resume from this bone onward
		EBAM_ANIMATED,

		//! The bone is not animated by the skin
		EBAM_UNANIMATED,

		//! Not an animation mode, just here to count the available modes
		EBAM_COUNT

	};

	//! Names for bone animation modes
	const c8* const BoneAnimationModeNames[] =
	{
		"automatic",
		"animated",
		"unanimated",
		0,
	};


	class IBoneSceneNode : public ISceneNode
	{
	public:

		IBoneSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id=-1) :
		  ISceneNode(parent, mgr, id) { }

		//! Returns the name of the bone
		virtual const c8* getBoneName() const = 0;

		//! Returns the index of the bone
		virtual u32 getBoneIndex() const = 0;

		//! Sets the animation mode of the bone. Returns true if successful.
		virtual bool setAnimationMode(E_BONE_ANIMATION_MODE mode) = 0;

		//! Gets the current animation mode of the bone
		virtual E_BONE_ANIMATION_MODE getAnimationMode() const = 0;

		//! returns the axis aligned bounding box of this node
		virtual const core::aabbox3d<f32>& getBoundingBox() const = 0;

		//! Returns the relative transformation of the scene node.
		//virtual core::matrix4 getRelativeTransformation() const = 0;

		virtual void OnAnimate(u32 timeMs) =0;

		//! Does nothing as bones are not visible
		virtual void render() { };

	};

} // end namespace scene
} // end namespace irr

#endif

