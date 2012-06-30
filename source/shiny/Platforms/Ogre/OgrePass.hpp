#ifndef SH_OGREPASS_H
#define SH_OGREPASS_H

#include <OgrePass.h>

#include "../../Main/Platform.hpp"

namespace sh
{
	class OgreMaterial;

	class OgrePass : public Pass
	{
	public:
		OgrePass (OgreMaterial* parent, const std::string& configuration);

		virtual boost::shared_ptr<TextureUnitState> createTextureUnitState ();
		virtual void assignVertexProgram (const std::string& name);
		virtual void assignFragmentProgram (const std::string& name);
		virtual void assignGeometryProgram (const std::string& name);

		Ogre::Pass* getOgrePass();

	private:
		Ogre::Pass* mPass;

	protected:
		virtual bool setPropertyOverride (const std::string &name, PropertyValuePtr& value, PropertySetGet* context);
	};
}

#endif