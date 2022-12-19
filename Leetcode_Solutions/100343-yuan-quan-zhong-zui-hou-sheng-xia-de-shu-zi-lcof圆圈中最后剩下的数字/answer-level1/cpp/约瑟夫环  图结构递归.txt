### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        return (m + f(n-1, m)) % n; //在不考虑溢出的情况下，(a%d + c)%d == (a+c)%d
    }
    int lastRemaining(int n, int m) {
        return f(n,m);
    }
};
```