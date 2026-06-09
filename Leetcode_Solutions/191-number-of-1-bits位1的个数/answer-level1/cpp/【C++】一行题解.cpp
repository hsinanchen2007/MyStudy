```
/*
 * Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: i love leetcode
 * Author: Nicolas
 * Create: 2019/10/18
 */
class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        return std::bitset<32>(n).count();
    }
};
```
