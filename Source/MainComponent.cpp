#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
    : magicState(dummyProcessor)
{
    // Создаем Magic GUI Editor
    magicEditor = std::make_unique<foleys::MagicPluginEditor>(magicState);
    addAndMakeVisible(magicEditor.get());

    setSize(800, 600);
}

MainComponent::~MainComponent()
{
    magicEditor = nullptr;
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    if (magicEditor)
        magicEditor->setBounds(getLocalBounds());
}
