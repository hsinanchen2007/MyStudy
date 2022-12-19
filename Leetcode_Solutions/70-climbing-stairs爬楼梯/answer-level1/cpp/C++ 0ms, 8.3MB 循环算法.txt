### 解题思路
斐波那契数列

![image.png](https://pic.leetcode-cn.com/9a4c277fb73ca019a1d6cc04efb9a5eea2b28025b389bd999a5704302f320210-image.png)

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int a = 1, b = 1, tmp;
        while(n > 1)
        {
            tmp = b;
            b = a + b;
            a = tmp;
            n --;
        }
        return b;
    }
};
```