/* *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare,
 *  Matthew Hausknecht, and the Reinforcement Learning and Artificial Intelligence
 *  Laboratory
 * Released under the GNU General Public License; see License.txt for details.
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 *  recordSAR.cpp
 *
 *  An example on recording frames, actions and rewards.
 **************************************************************************** */

#include <iostream>
#include <ale_interface.hpp>
#include <cstdlib>

//#ifndef __USE_SDL
//#error Video recording example is disabled as it requires SDL. Recompile with -DUSE_SDL=ON.
//#else

#include <SDL.h>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " rom_file [recording_path]" << std::endl;
        return 1;
    }

    ALEInterface ale;

    bool recordSound = false;

    // Set fragsize to 64 to ensure proper sound sync
    int fragsize = 64;
    std::string rom_file = argv[1];

    // Get & Set the desired settings
    ale.setInt("random_seed", 123);

    // We enable both screen and sound, which we will need for recording.
    ale.setBool("display_screen", true);
    // You may leave sound disabled (by setting this flag to false) if so desired.
    ale.setBool("sound", recordSound);

    std::string recordPath = "record";
    if (argc > 2) {
        recordPath = argv[2];
    }
    std::cout << "saving recording to " << recordPath << std::endl;

    // Set record flags
    ale.setString("record_screen_dir", recordPath.c_str());
    ale.setString("record_sound_filename", (recordPath + "/sound.wav").c_str());
    ale.setString("record_rewards_filename",  (recordPath + "/rewards.csv").c_str());
    ale.setInt("fragsize", fragsize);

    // Not completely portable, but will work in most cases
    std::string cmd = "mkdir ";
    cmd += recordPath;
    system(cmd.c_str());

    // Load the ROM file. (Also resets the system for new settings to
    // take effect.)
    std::cout << "loading rom file " << rom_file << std::endl;
    ale.loadROM(rom_file);

    ale.theOSystem->p_display_screen->engage_manual_control();

    // Play a single episode, which we record.
    // The given action will be overridden by manual control.
    while (!ale.game_over()) {
        Action a;
        ale.act(a);
    }

    std::cout << std::endl;
    std::cout << "Recording complete. To create a video, you may want to run \n"
        "  doc/scripts/videoRecordingExampleJoinXXX.sh. See manual for details.." << std::endl;


    return 0;
}

//#endif // __USE_SDL
