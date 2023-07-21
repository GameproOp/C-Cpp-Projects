#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        cout << "SDL initialization failed: " << SDL_GetError() << endl;
        return 1;
    }

    // Load the audio file
    const char* audioFile = "example.wav";
    SDL_AudioSpec spec;
    Uint32 length;
    Uint8* buffer;

    if (SDL_LoadWAV(audioFile, &spec, &buffer, &length) == NULL) {
        cout << "Failed to load audio: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Open audio device
    SDL_AudioDeviceID audioDevice = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
    if (audioDevice == 0) {
        cout << "Failed to open audio device: " << SDL_GetError() << endl;
        SDL_FreeWAV(buffer);
        SDL_Quit();
        return 1;
    }

    // Play the audio
    SDL_PauseAudioDevice(audioDevice, 0);
    cout << "Playing audio..." << endl;

    // Wait for the audio to finish playing
    SDL_Delay(spec.duration);

    // Clean up
    SDL_CloseAudioDevice(audioDevice);
    SDL_FreeWAV(buffer);
    SDL_Quit();

    cout << "Audio playback finished." << endl;
    return 0;
}
