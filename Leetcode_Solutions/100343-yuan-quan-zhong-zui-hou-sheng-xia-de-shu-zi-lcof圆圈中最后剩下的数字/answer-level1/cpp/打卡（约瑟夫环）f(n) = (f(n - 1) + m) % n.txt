### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int f(int n, int& m) {
        // m - 1 out
        if (n == 1) return 0;
        return (f(n - 1,m) + m) % n;
    }

    int lastRemaining(int n, int m) {
        return f(n, m);

    }
};
```