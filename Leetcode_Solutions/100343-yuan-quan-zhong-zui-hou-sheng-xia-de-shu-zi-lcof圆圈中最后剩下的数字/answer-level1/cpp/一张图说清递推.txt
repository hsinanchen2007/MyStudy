### 解题思路

![IMG_20200330_180523.jpg](https://pic.leetcode-cn.com/754f2cb7ff97bf41aacac32f4ab95111363d132ade0bf504de4df41a3db3d8ac-IMG_20200330_180523.jpg)

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i = 2; i <= n; ++i)
        {
            ans = (ans + m) % i;
        }
        return ans;
    }
};
```