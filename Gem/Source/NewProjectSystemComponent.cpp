
#include <AzCore/Serialization/SerializeContext.h>

#include "NewProjectSystemComponent.h"

#include <NewProject/NewProjectTypeIds.h>

namespace NewProject
{
    AZ_COMPONENT_IMPL(NewProjectSystemComponent, "NewProjectSystemComponent",
        NewProjectSystemComponentTypeId);

    void NewProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<NewProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void NewProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("NewProjectService"));
    }

    void NewProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("NewProjectService"));
    }

    void NewProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void NewProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    NewProjectSystemComponent::NewProjectSystemComponent()
    {
        if (NewProjectInterface::Get() == nullptr)
        {
            NewProjectInterface::Register(this);
        }
    }

    NewProjectSystemComponent::~NewProjectSystemComponent()
    {
        if (NewProjectInterface::Get() == this)
        {
            NewProjectInterface::Unregister(this);
        }
    }

    void NewProjectSystemComponent::Init()
    {
    }

    void NewProjectSystemComponent::Activate()
    {
        NewProjectRequestBus::Handler::BusConnect();
    }

    void NewProjectSystemComponent::Deactivate()
    {
        NewProjectRequestBus::Handler::BusDisconnect();
    }
}
