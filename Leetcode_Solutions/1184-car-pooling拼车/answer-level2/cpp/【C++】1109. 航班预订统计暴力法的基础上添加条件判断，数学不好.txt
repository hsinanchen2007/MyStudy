1.使用map记录所有经停站的信息，遍历所有经停站，先下后上。
2.判断是否超过capacity

[一句话题解我看懂了](https://leetcode-cn.com/problems/car-pooling/solution/1094-pin-che-by-acj/)

```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2020/02/18
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        const int maxStationCount = 1000;
        vector<int> stationInfo(maxStationCount, 0);
        for (vector<vector<int>>::const_iterator iter = trips.begin();
                iter != trips.end();
                ++iter) {
            const vector<int> & record = *iter;
            const int countPosition = 0;
            int count = record.at(countPosition);
            const int fromPosition = 1;
            int from = record.at(fromPosition);
            const int toPosition = 2;
            int to = record.at(toPosition);
            if (from < 0 || from > maxStationCount) {
                return false;
            }
            if (to < 0 || to > maxStationCount) {
                return false;
            }

            if (from >= to) {
                return false;
            }

            for (int index = from; index < to; index++) {
                stationInfo[index - 1] += count;
                if (stationInfo[index - 1] > capacity) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
