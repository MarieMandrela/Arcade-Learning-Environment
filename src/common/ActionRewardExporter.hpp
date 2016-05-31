/* *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare and
 *   the Reinforcement Learning and Artificial Intelligence Laboratory
 * Released under the GNU General Public License; see License.txt for details.
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 *  ActionRewardExporter.hpp
 *
 *  A class for exporting actions and rewards as csv file.
 *
 **************************************************************************** */

#ifndef __ACTION_REWARD_EXPORTER_HPP__
#define __ACTION_REWARD_EXPORTER_HPP__

#include <iostream>
#include <fstream>
#include "../common/Constants.h"

class ActionRewardExporter {

    public:

        /** Creates a new ActionRewardExporter which will save actions and rewards successively in the file provided.
            Format is csv. Actual file name may vary. Data is appended. */
        ActionRewardExporter(const std::string &file_name);
        /** On program determination flushes data and closes file. */
        ~ActionRewardExporter();

        /** Save the given action and reward. */
        void saveNext(const Action action, const reward_t reward);

    private:

        /** The width of the frame number when constructing filenames (set to 6). */
        std::ofstream m_stream;

        /** The directory where we save successive frames. */
        std::string m_file_name;
};

#endif // __ACTION_REWARD_EXPORTER_HPP__

