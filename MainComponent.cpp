#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //SETTING SLIDER AND BUTTON ATTRIBUTES
    
    //GENERATE BUTTON
    addAndMakeVisible(generateButton);
    generateButton.setButtonText("Generate");
    generateButton.onClick = [this] {generateFile();};
    
    //SLIDERS
    midiSlider.setSliderStyle (juce::Slider::LinearBar);
    midiSlider.setRange (0.0, 127.0, 1.0);
    midiSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    midiSlider.setPopupDisplayEnabled (true, false, this);
    midiSlider.setTextValueSuffix (": MIDI Note");
    midiSlider.setValue(60.0);
    midiSlider.setDoubleClickReturnValue(true, 60.0);
    addAndMakeVisible(&midiSlider);
    
    harmonicsSlider.setSliderStyle (juce::Slider::LinearBar);
    harmonicsSlider.setRange (1.0, 100.0, 1.0);
    harmonicsSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    harmonicsSlider.setPopupDisplayEnabled (true, false, this);
    harmonicsSlider.setTextValueSuffix ("%: Percentage of Harmonics");
    harmonicsSlider.setValue(100.0);
    harmonicsSlider.setDoubleClickReturnValue(true, 100.0);
    addAndMakeVisible(&harmonicsSlider);
    
    lengthSlider.setSliderStyle (juce::Slider::LinearBar);
    lengthSlider.setRange (1.0, 20.0, 1.0);
    lengthSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    lengthSlider.setPopupDisplayEnabled (true, false, this);
    lengthSlider.setTextValueSuffix (" Sec: Length of Audio");
    lengthSlider.setValue(2.0);
    lengthSlider.setDoubleClickReturnValue(true, 2.0);
    addAndMakeVisible(&lengthSlider);
    
    panSlider.setSliderStyle (juce::Slider::LinearBar);
    panSlider.setRange (0.0, 100.0, 1.0);
    panSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    panSlider.setPopupDisplayEnabled (true, false, this);
    panSlider.setTextValueSuffix ("%: Pan Position (Left to Right)");
    panSlider.setValue(50.0);
    panSlider.setDoubleClickReturnValue(true, 50.0);
    addAndMakeVisible(&panSlider);
    
    gainSlider.setSliderStyle (juce::Slider::LinearBar);
    gainSlider.setRange (-80.0, 0.0, 1.0);
    gainSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    gainSlider.setPopupDisplayEnabled (true, false, this);
    gainSlider.setTextValueSuffix ("dB: Gain");
    gainSlider.setValue(-6.0);
    gainSlider.setDoubleClickReturnValue(true, -6.0);
    addAndMakeVisible(&gainSlider);
    
    //RADIO GROUP TOGGLE BUTTONS
    addAndMakeVisible(sampleRate44k);
    sampleRate44k.setButtonText("44.1kHz");
    sampleRate44k.setRadioGroupId(sampleRateGroup);
    sampleRate44k.setToggleState(true, true);

    
    addAndMakeVisible(sampleRate48k);
    sampleRate48k.setButtonText("48kHz");
    sampleRate48k.setRadioGroupId(sampleRateGroup);
    
    addAndMakeVisible(sampleRate88k);
    sampleRate88k.setButtonText("88.2kHz");
    sampleRate88k.setRadioGroupId(sampleRateGroup);
    
    addAndMakeVisible(sampleRate96k);
    sampleRate96k.setButtonText("96kHz");
    sampleRate96k.setRadioGroupId(sampleRateGroup);
    
    addAndMakeVisible(bitDepth8);
    bitDepth8.setButtonText("8 bit");
    bitDepth8.setRadioGroupId(bitRateGroup);
    bitDepth8.setToggleState(true, true);
    
    addAndMakeVisible(bitDepth16);
    bitDepth16.setButtonText("16 bit");
    bitDepth16.setRadioGroupId(bitRateGroup);
    
    addAndMakeVisible(bitDepth24);
    bitDepth24.setButtonText("24 bit");
    bitDepth24.setRadioGroupId(bitRateGroup);
    
    addAndMakeVisible(bitDepth32);
    bitDepth32.setButtonText("32 bit");
    bitDepth32.setRadioGroupId(bitRateGroup);
    
    addAndMakeVisible(formatWav);
    formatWav.setButtonText("WAV");
    formatWav.setRadioGroupId(formatGroup);
    formatWav.setToggleState(true, true);
    
    addAndMakeVisible(formatOgg);
    formatOgg.setButtonText("OGG");
    formatOgg.setRadioGroupId(formatGroup);
    
    addAndMakeVisible(formatFlac);
    formatFlac.setButtonText("FLAC");
    formatFlac.setRadioGroupId(formatGroup);
    
    addAndMakeVisible(formatAiff);
    formatAiff.setButtonText("AIFF");
    formatAiff.setRadioGroupId(formatGroup);
    
    addAndMakeVisible(chordMaj);
    chordMaj.setButtonText("Major");
    chordMaj.setRadioGroupId(chordGroup);
    chordMaj.setToggleState(true, true);
    
    addAndMakeVisible(chordMin);
    chordMin.setButtonText("Minor");
    chordMin.setRadioGroupId(chordGroup);
    
    addAndMakeVisible(waveSquare);
    waveSquare.setButtonText("Square");
    waveSquare.setRadioGroupId(waveGroup);
    waveSquare.setToggleState(true, true);
    
    addAndMakeVisible(waveSaw);
    waveSaw.setButtonText("Sawtooth");
    waveSaw.setRadioGroupId(waveGroup);

    // TOGGLE BUTTON LABELS
    addAndMakeVisible (sampleRateLabel);
    sampleRateLabel.setText ("Sample Rate", juce::dontSendNotification);
    sampleRateLabel.attachToComponent(&sampleRate44k, false);
    
    addAndMakeVisible (bitDepthLabel);
    bitDepthLabel.setText ("Bit Depth", juce::dontSendNotification);
    bitDepthLabel.attachToComponent(&bitDepth8, false);
    
    addAndMakeVisible (formatLabel);
    formatLabel.setText ("Audio Format", juce::dontSendNotification);
    formatLabel.attachToComponent(&formatWav, false);
    
    addAndMakeVisible (chordLabel);
    chordLabel.setText ("Chord Type", juce::dontSendNotification);
    chordLabel.attachToComponent(&chordMaj, false);
    
    addAndMakeVisible (waveLabel);
    waveLabel.setText ("Waveshape", juce::dontSendNotification);
    waveLabel.attachToComponent(&waveSquare, false);
    
    addAndMakeVisible (titleLabel);
    titleLabel.setText ("Complex Wave Generator", juce::dontSendNotification);
    titleLabel.attachToComponent(&generateButton, false);
    titleLabel.setJustificationType (juce::Justification::centred);
    
    setSize (500, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll(juce::Colours::black);
    
    //PAINTING BUTTON
    generateButton.setColour(juce::TextButton::buttonColourId, juce::Colours::silver);
    generateButton.setColour(juce::TextButton::textColourOffId, juce::Colours::black);
    
    //PAINTING TITLE
    titleLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    
    //PAINTING SLIDERS
    getLookAndFeel().setColour(juce::Slider::trackColourId, juce::Colours::silver);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    //POSITIONING SLIDERS AND BUTTONS
    midiSlider.setBoundsRelative(0.1875, 0.20, 0.625, 0.05);
    harmonicsSlider.setBoundsRelative(0.1875, 0.26, 0.625, 0.05);
    lengthSlider.setBoundsRelative(0.1875, 0.32, 0.625, 0.05);
    panSlider.setBoundsRelative(0.1875, 0.38, 0.625, 0.05);
    gainSlider.setBoundsRelative(0.1875, 0.44, 0.625, 0.05);
    
    generateButton.setBoundsRelative(0.35, 0.07, 0.3, 0.1);
    
    sampleRate44k.setBoundsRelative(0.1, 0.595, 0.3, 0.075);
    sampleRate48k.setBoundsRelative(0.1, 0.67, 0.3, 0.075);
    sampleRate88k.setBoundsRelative(0.1, 0.745, 0.3, 0.075);
    sampleRate96k.setBoundsRelative(0.1, 0.82, 0.3, 0.075);
    
    bitDepth8.setBoundsRelative(0.325, 0.595, 0.3, 0.075);
    bitDepth16.setBoundsRelative(0.325, 0.67, 0.3, 0.075);
    bitDepth24.setBoundsRelative(0.325, 0.745, 0.3, 0.075);
    bitDepth32.setBoundsRelative(0.325, 0.82, 0.3, 0.075);
    
    formatWav.setBoundsRelative(0.55, 0.595, 0.3, 0.075);
    formatOgg.setBoundsRelative(0.55, 0.67, 0.3, 0.075);
    formatFlac.setBoundsRelative(0.55, 0.745, 0.3, 0.075);
    formatAiff.setBoundsRelative(0.55, 0.82, 0.3, 0.075);
    
    chordMaj.setBoundsRelative(0.775, 0.595, 0.3, 0.075);
    chordMin.setBoundsRelative(0.775, 0.67, 0.3, 0.075);
    
    waveSquare.setBoundsRelative(0.775, 0.82, 0.3, 0.075);
    waveSaw.setBoundsRelative(0.775, 0.895, 0.3, 0.075);
}

void MainComponent::generateFile()
{
    //GETTING DATA FOR AUDIO FILE FROM HEADER FILE
    float midi = midiSlider.getValue();
    float harmonicMultiplier = harmonicsSlider.getValue();
    float length = lengthSlider.getValue();
    float userPanPos = panSlider.getValue();
    float fileGain = gainSlider.getValue();
    
    //GETTING DATA FROM RADIO GROUPED TOGGLE BUTTONS
    float sampleRate = 44100;
    if (sampleRate44k.getToggleState() == true){
        sampleRate = 44100;
    } else if (sampleRate48k.getToggleState() == true){
        sampleRate = 48000;
    } else if (sampleRate88k.getToggleState() == true){
        sampleRate = 88200;
    } else if (sampleRate96k.getToggleState() == true){
        sampleRate = 96000;
    }
        
    int bitDepth = 8;
    if (bitDepth8.getToggleState() == true){
        bitDepth = 8;
    } else if (bitDepth16.getToggleState() == true){
        bitDepth = 16;
    } else if (bitDepth24.getToggleState() == true){
        bitDepth = 24;
    } else if (bitDepth32.getToggleState() == true){
        bitDepth = 32;
    }
    
    std::string audioFormat = "wav";
    if (formatWav.getToggleState() == true){
        audioFormat = "wav";
    } else if (formatOgg.getToggleState() == true){
        audioFormat = "ogg";
    } else if (formatFlac.getToggleState() == true){
        audioFormat = "flac";
    } else if (formatAiff.getToggleState() == true){
        audioFormat = "aiff";
    }
    
    float chordType = 1.25;
    if (chordMaj.getToggleState() == true){
        chordType = 1.25;
    } else if (chordMin.getToggleState() == true){
        chordType = 1.2;
    }
    
    std::string waveType = "square";
    if (waveSquare.getToggleState() == true){
        waveType = "square";
    } else if (waveSaw.getToggleState() == true){
        waveType = "saw";
    }
    
    
    //FIND NOTE NAME FROM MIDI VALUE
    int octave = (midi / 12) - 1;
    std::string noteNameArr[]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    std::string noteLetter = noteNameArr[(int)midi % 12];
    
    
    //MIDI TO FREQ CONVERSION
    float freq = 440 * (pow(2, ((midi - 69) / 12)));
    
    
    //NOTE FREQUENCY VECTOR
    std::vector<float> noteFreq;
    noteFreq.resize(3);
    noteFreq[0] = freq;
    noteFreq[1] = freq * chordType;
    noteFreq[2] = freq * 1.5;
    
    
    //WAVE GENERATION
    int numChannels = 2;
    float panPos = userPanPos / 100; //SCALING USER INPUT FOR PANNING
    panPos *= M_PI / 2.0;
    
    
    juce::AudioBuffer<float> buffer;
    buffer.setSize(numChannels, sampleRate * length);
    for (int channel = 0; channel < buffer.getNumChannels(); channel++) {
        auto bufferPointer = buffer.getWritePointer(channel);
        
        
            for (int sample = 0; sample < sampleRate * length; sample++) //COUNTING SAMPLES
            {
                float amplitudeOfSample = 0;
            
                for (int note = 0; note < noteFreq.size(); note++) //COUNTING NOTES
                {
                    float thisNoteAmplitude = amplitudeOfSample;
                
                    if (waveType == "square"){ //SQUARE WAVE GENERATION
                        
                        waveShapeType squareWave; //CUSTOM CLASS OBJECT
                        
                        for (squareWave.maxFreq = noteFreq[note]; squareWave.maxFreq < (sampleRate / 2); squareWave.maxFreq = noteFreq[note] * (2 * squareWave.i - 1)) //ODD HARMONICS
                        {
                            squareWave.maxHarmonics = squareWave.i;
                            squareWave.i++;
                        } //CALCULATING MAXIMUM HARMONICS ALLOWED WHILE PREVENTING ALIASING
                        
                        squareWave.getKLimit(harmonicMultiplier); //CALLS CLASS METHOD TO FIND kLimit
                        
                        for (int k = 1; k <= squareWave.kLimit; k++){ //CYCLES THROUGH CHOSEN AMOUNT OF HARMONICS BETWEEN 1 AND kLimit
                            squareWave.harmonicAmplitude = (sin(M_PI * 2 * (2 * k - 1) * noteFreq[note] * (sample / sampleRate))) / (2 * k - 1);
                            amplitudeOfSample += squareWave.harmonicAmplitude; } //SQUARE WAVE HARMONICS
                        
                    } else if (waveType == "saw"){ //SAWTOOTH WAVE GENERATION
                        
                        waveShapeType sawWave; //CUSTOM CLASS OBJECT
                        
                        for (sawWave.maxFreq = noteFreq[note]; sawWave.maxFreq < (sampleRate / 2); sawWave.maxFreq = noteFreq[note] * sawWave.i) //ODD AND EVEN HARMONICS
                        {
                            sawWave.maxHarmonics = sawWave.i;
                            sawWave.i++;
                        } //CALCULATING MAXIMUM HARMONICS ALLOWED WHILE PREVENTING ALIASING
                        
                        sawWave.getKLimit(harmonicMultiplier); //CALLS CLASS METHOD TO FIND kLimit
                        
                        for (int k = 1; k <= sawWave.kLimit; k++){ //CYCLES THROUGH CHOSEN AMOUNT OF HARMONICS BETWEEN 1 AND kLimit
                            sawWave.harmonicAmplitude = pow(-1, k) * (sin(M_PI * 2 * k * noteFreq[note] * (sample / sampleRate)) / k);
                            amplitudeOfSample += sawWave.harmonicAmplitude; } //SAWTOOTH WAVE HARMONICS
                    }
                
                    amplitudeOfSample += thisNoteAmplitude;
                }
                bufferPointer[sample] = amplitudeOfSample / noteFreq.size();
            
                if (numChannels > 1) {
                    if (channel == 0) { //LEFT CHANNEL
                        bufferPointer[sample] *= std::cos(panPos);
                    } else              //RIGHT CHANNEL
                    {
                        bufferPointer[sample] *= std::sin(panPos);
                    }
                }
            }
        }
    
    //NORMALISING GAIN
    buffer.applyGain(1.0 / buffer.getMagnitude(0, buffer.getNumSamples()));
    buffer.applyGain(juce::Decibels::decibelsToGain(fileGain));
    
    //SAVING FILES AS
    juce::FileChooser fileChoice("Save As");
    if (fileChoice.browseForFileToSave(true))
    {
    
    //FILE GENERATION SELECTION
    if (audioFormat == "wav") {
        juce::WavAudioFormat format;
        audioWriter(fileChoice, audioFormat, format, sampleRate, numChannels, bitDepth, buffer);
    } else if (audioFormat == "ogg") {
        juce::OggVorbisAudioFormat format;
        audioWriter(fileChoice, audioFormat, format, sampleRate, numChannels, bitDepth, buffer);
    } else if (audioFormat == "flac") {
        juce::FlacAudioFormat format;
        audioWriter(fileChoice, audioFormat, format, sampleRate, numChannels, bitDepth, buffer);
    } else if (audioFormat == "aiff") {
        juce::AiffAudioFormat format;
        audioWriter(fileChoice, audioFormat, format, sampleRate, numChannels, bitDepth, buffer);
        }
    }
    
    //WRITING LOG .txt FILE
    juce::File file = fileChoice.getResult();
    juce::String fileName = file.getFileNameWithoutExtension();
    fileName += ".txt";
    juce::File fileWithCorrectExtension(file.getParentDirectory().getChildFile(fileName));
    fileWithCorrectExtension.deleteFile();
    fileWithCorrectExtension.create();
    
    //PRINTING AUDIO FILE DATA TO .txt FILE
    juce::String stringToOutput("The user chose: ");
    stringToOutput += "\nMIDI note: ";
    stringToOutput += (int)midi;
    stringToOutput += "\nSample rate: ";
    stringToOutput << sampleRate / 1000;
    stringToOutput += "kHz";
    stringToOutput += "\nBit Depth: ";
    stringToOutput += bitDepth;
    stringToOutput += "\nPercentage of harmonics: ";
    stringToOutput += (int)harmonicMultiplier;
    stringToOutput += "%";
    stringToOutput += "\nLength of file: ";
    stringToOutput << length;
    stringToOutput += " seconds.";
    stringToOutput += "\nPan positioning: ";
    stringToOutput << userPanPos;
    stringToOutput += "%";
    stringToOutput += "\nNormalised at: ";
    stringToOutput << fileGain;
    stringToOutput += "dB";
    if (chordType == 1.25) {
        stringToOutput += "\nA MAJOR chord";
    } else {
        stringToOutput += "\nA MINOR chord";
    }
    stringToOutput += " with root note: ";
    stringToOutput << noteLetter;
    stringToOutput += octave;
    stringToOutput += "\nAudio format: ";
    if (audioFormat == "wav") {
        stringToOutput += "WAV";
    } else if (audioFormat == "ogg") {
        stringToOutput += "Ogg Vorbis";
    } else if (audioFormat == "flac") {
        stringToOutput += "FLAC";
    } else if (audioFormat == "aiff") {
        stringToOutput += "AIFF";
    }
    stringToOutput += "\nWaveshape: ";
    if (waveType == "square"){
        stringToOutput += "Square wave";
    } else if (waveType == "saw"){
        stringToOutput += "Sawtooth wave";
    }
    if (audioFormat != "wav" && bitDepth == 32){
        stringToOutput += "\nERROR: 32bit FLAC and AIFF files are not supported by JUCE!";
    }
    if (audioFormat == "flac" && bitDepth == 8){
        stringToOutput += "\nERROR: 8bit FLAC files are not supported by JUCE!";
    }
    fileWithCorrectExtension.replaceWithText(stringToOutput);

}
