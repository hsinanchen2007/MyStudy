### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int plan[n];
        plan[0] = 1;
        plan[1] = 2;
        for(int k = 2;k<n;k++)
        plan[k] = plan[k-1]+plan[k-2];

        return plan[n-1];
        



    }
};
```