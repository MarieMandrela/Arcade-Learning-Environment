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

#include "ActionRewardExporter.hpp"
#include "Log.hpp"

ActionRewardExporter::ActionRewardExporter(const std::string &file_name):
    m_file_name(file_name) {
    m_stream.open(file_name.c_str());
    if (m_stream.fail()) {
        ale::Logger::Error << "Could not open " << file_name << " for writing" << std::endl;
    }
}

ActionRewardExporter::~ActionRewardExporter() {
    m_stream.flush();
    m_stream.close();
}

void ActionRewardExporter::saveNext(const Action action, const reward_t reward) {
    m_stream << action << "," << reward << std::endl;
}


