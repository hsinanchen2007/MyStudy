![image.png](https://pic.leetcode-cn.com/5c97ad1564b4bd195fcd7141a2bac12f29b003b5e146e7b84c45eebb3002c44f-image.png)

```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2020/02/18
 */

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> result(n, 0);
        for (vector<vector<int>>::const_iterator iter = bookings.begin();
                iter != bookings.end();
                ++iter) {
            const vector<int> & record = *iter;
            const int validRecordLength = 3;
            if (record.size() != validRecordLength) {
                continue;
            }
            const int fromPosition = 0;
            const int toPosition = 1;
            const int countPosition = 2;
            int i = record.at(fromPosition);
            int j = record.at(toPosition);
            int count = record.at(countPosition);
            if (i < 1 || j < 1) {
                continue;
            }
            if (count < 0) {
                continue;
            }
            if (i == j) {
                result[i - 1] += count;
            } else {
                for (int index = i; index <= j; ++index) {
                    result[index - 1] += count;
                }
            }
        }
        return result;
    }
};
```
