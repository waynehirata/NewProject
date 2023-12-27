
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "NewProjectSystemComponent.h"

#include <NewProject/NewProjectTypeIds.h>

namespace NewProject
{
    class NewProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(NewProjectModule, NewProjectModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(NewProjectModule, AZ::SystemAllocator);

        NewProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                NewProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<NewProjectSystemComponent>(),
            };
        }
    };
}// namespace NewProject

AZ_DECLARE_MODULE_CLASS(Gem_NewProject, NewProject::NewProjectModule)
