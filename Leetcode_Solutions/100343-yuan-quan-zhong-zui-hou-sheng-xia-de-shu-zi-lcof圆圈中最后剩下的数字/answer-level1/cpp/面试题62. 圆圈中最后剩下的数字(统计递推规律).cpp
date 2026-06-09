### 题目描述
![image.png](https://pic.leetcode-cn.com/4534714e57d603b46e97d6d56a8c551a367e221f45f58573eb089d4c8b3b3784-image.png)

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i <= n; i++) {
            f = (f + m) % i;
        }
        return f;
    }
};
```