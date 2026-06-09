### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int pre_pre = 1, pre = 2;
        int cur = -1;
        for(int i = 3; i <= n; i++){
            cur = pre_pre + pre;
            pre_pre = pre;
            pre = cur;
        }
        return cur;
    }
};
```