### 解题思路
此处撰写解题思路

动态规划，从底往顶
用大小为2的滚动数组，存储前面2个阶梯的可能数据。

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        int sz[2] = {1,2};
        int t = 0;
        for(int i=2;i<n;i++)
        {
            t = sz[0] + sz[1];
            sz[0] = sz[1];
            sz[1] = t;
        }
        return sz[1];
    }
};
```