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

#ifndef __JOBRESULT_H__
#define __JOBRESULT_H__


#include <stdint.h>
#include <string.h>


#include "net/JobId.h"


class JobResult
{
public:
    inline JobResult() :
        nonce(nullptr),
        result(nullptr),
        id(0),
        diff(0)
    {
    }

    JobResult(int64_t id, const char *jobId, const char *nonce, const char *result);

    bool isCompatible(uint8_t fixedByte) const;
    bool isValid() const;
    uint64_t actualDiff() const;

    const char *nonce;
    const char *result;
    const int64_t id;
    JobId jobId;
    uint32_t diff;

private:
    mutable uint64_t m_actualDiff;
};

#endif /* __JOBRESULT_H__ */
