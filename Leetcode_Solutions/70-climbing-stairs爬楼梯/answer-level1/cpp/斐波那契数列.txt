### 解题思路
这就是个斐波那契数列。。。没啥好说的

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int ans[n+1];
        ans[0] = ans[1] = 1;
        for (int i=2; i<=n; i++) {
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};
```