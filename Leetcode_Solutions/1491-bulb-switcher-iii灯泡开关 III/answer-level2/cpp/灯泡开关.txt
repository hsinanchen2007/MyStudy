### 解题思路
主要就是看目前的数是不是最大的，是就代表所有灯都是蓝色的。

### 代码

```cpp
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int count = light.size();
        int max = 0;
        for (int i = 0; i < count; ++i)
        {
            if (max == i)
                ++res;
            if (light[i] > max)
                max = light[i];
        }
        return res;
    }
};
```