### 解题思路
![1.png](https://pic.leetcode-cn.com/9a8fe6e6b2dac6d3edf5e75e59c96bb3197bd18f00b2e8ddf57e93d913bbbd3d-1.png)

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int rCnt = 0,lCnt = 0,res = 0;

        for (auto cur:s) {
            if (cur == 'R') 
                rCnt++;
            else
                lCnt++;
            if(rCnt == lCnt)
                res++;
        }
    return res;
    }
};
```