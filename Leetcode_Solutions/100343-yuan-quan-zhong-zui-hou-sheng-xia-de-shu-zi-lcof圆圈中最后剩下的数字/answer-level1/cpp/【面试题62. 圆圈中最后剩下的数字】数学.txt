## 思路一：数学+迭代


### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i != n + 1; ++i)
            f = (m + f) % i;
        return f;
    }
};
```