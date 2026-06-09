### 解题思路
约瑟夫环递推公式：
f(n, m) = 0 (n = 1)
f(n, m) = (f(n - 1, m) + m) % n (n > 1)

### 代码

```cpp
class Solution {
public:
int lastRemaining(int n, int m) {
    /*if(n == 1)
        return 0;
    
    return (lastRemaining(n - 1, m) + m) % n;*/
    int f = 0;
    for (int i = 1; i <= n; i++) 
        f = (f + m) % i;
    return f;
}
};
```