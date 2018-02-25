/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2016-2017 XMRig       <support@xmrig.com>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __STATS_H__
#define __STATS_H__


#include <stdint.h>


#include "interfaces/IEventListener.h"
#include "proxy/StatsData.h"
#include "proxy/TickingCounter.h"


class AcceptEvent;
class NonceSplitter;


class Stats : public IEventListener
{
public:
    Stats();
    ~Stats();

    void tick(uint64_t ticks, const NonceSplitter &splitter);

    inline const StatsData &data() const      { return m_data; }
    inline double hashrate(int seconds) const { return m_hashrate.calc(seconds); }

protected:
    void onEvent(IEvent *event) override;
    void onRejectedEvent(IEvent *event) override;

private:
    void accept(const AcceptEvent *event);
    void reject(const AcceptEvent *event);

    StatsData m_data;
    TickingCounter<uint32_t> m_hashrate;
};


#endif /* __STATS_H__ */
