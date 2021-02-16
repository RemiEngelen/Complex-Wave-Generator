#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/


//CUSTOM CLASS FOR GENERATING THE WAVE HARMONICS
class waveShapeType{
public:
    float harmonicAmplitude;
    int kLimit = 1;
    float maxFreq;
    int i = 1;
    int maxHarmonics = 1;
    void getKLimit(float& harmonicMultiplier)
    {
        kLimit = (maxHarmonics) * (harmonicMultiplier / 100); //CALCULATE USER CHOSEN AMOUNT OF HARMONICS
        if (kLimit < 1) {kLimit++;} //ENSURES kLimit IS ALWAYS >= 1 DUE TO FLOAT TO INT TRUNCATION SETTING kLimit to 0 IN SOME INSTANCES
    }
};



class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void generateFile();
    
    //CLASS METHOD TO WRITE AUDIO TO SELECTED FILE
    void audioWriter(juce::FileChooser& fileChoice, std::string& audioFormat, juce::AudioFormat& format, float& sampleRate, int& numChannels, int& bitDepth, juce::AudioBuffer<float>& buffer)
    {
        juce::File file = fileChoice.getResult();
        juce::String fileName = file.getFileNameWithoutExtension();
        fileName += ".";
        fileName << audioFormat;
        juce::File fileWithCorrectExtension(file.getParentDirectory().getChildFile(fileName));
        fileWithCorrectExtension.deleteFile();
        fileWithCorrectExtension.create();
        std::unique_ptr<juce::AudioFormatWriter> writer;
        writer.reset(format.createWriterFor(new juce::FileOutputStream(fileWithCorrectExtension),sampleRate, numChannels, bitDepth, {}, 0));
        if (writer != nullptr){
        writer->writeFromAudioSampleBuffer(buffer, 0, buffer.getNumSamples());
        }}

private:
    //==============================================================================
    // Your private member variables go here...
    juce::Slider midiSlider;
    juce::Slider harmonicsSlider;
    juce::Slider lengthSlider;
    juce::Slider panSlider;
    juce::Slider gainSlider;
    juce::TextButton generateButton;
    juce::ToggleButton sampleRate44k;
    juce::ToggleButton sampleRate48k;
    juce::ToggleButton sampleRate88k;
    juce::ToggleButton sampleRate96k;
    juce::ToggleButton bitDepth8;
    juce::ToggleButton bitDepth16;
    juce::ToggleButton bitDepth24;
    juce::ToggleButton bitDepth32;
    juce::ToggleButton formatWav;
    juce::ToggleButton formatOgg;
    juce::ToggleButton formatFlac;
    juce::ToggleButton formatAiff;
    juce::ToggleButton chordMaj;
    juce::ToggleButton chordMin;
    juce::ToggleButton waveSquare;
    juce::ToggleButton waveSaw;
    
    juce::Label sampleRateLabel;
    juce::Label bitDepthLabel;
    juce::Label formatLabel;
    juce::Label chordLabel;
    juce::Label waveLabel;
    juce::Label titleLabel;
   
    //ASSIGNING RADIO BUTTON GROUPS
    enum RadioButtonIds
    {
        sampleRateGroup = 1001,
        bitRateGroup = 1002,
        formatGroup = 1003,
        chordGroup = 1004,
        waveGroup = 1005
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
