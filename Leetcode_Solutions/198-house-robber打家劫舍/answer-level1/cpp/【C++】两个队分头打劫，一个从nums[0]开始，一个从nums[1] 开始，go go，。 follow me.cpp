follow me：
两个队分头打劫，一个从nums[0]开始，一个从nums[1] 开始，go go，。 follow me
```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/19
 */
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int odd = 0;
        int even = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (isEven(i)) {
                even += nums.at(i);
                even = followMe(even, odd);
            } else {
                odd += nums.at(i);
                odd = followMe(odd, even);
            }
        }
        return max(odd, even);
    }

private:
    bool isEven(int i)
    {
        return i & 0x1 == 0x01;
    }

    int followMe(int even, int odd)
    {
        int more = max(odd, even);
        return more;
    }
};
```
