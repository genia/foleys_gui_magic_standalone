#pragma once

#include <JuceHeader.h>
#include <foleys_gui_magic/foleys_gui_magic.h>
#include "DummyProcessor.h"

//==============================================================================
class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    DummyProcessor dummyProcessor;  // Используем DummyProcessor вместо juce::AudioProcessor
    foleys::MagicProcessorState magicState;
    std::unique_ptr<foleys::MagicPluginEditor> magicEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
