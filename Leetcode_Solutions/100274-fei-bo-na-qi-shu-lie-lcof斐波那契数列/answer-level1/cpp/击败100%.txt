### 解题思路
![image.png](https://pic.leetcode-cn.com/37727162ce645c6049e6bda83008e72c96afb81a68e6cc54626362007f0b0fe8-image.png)


### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        long long a = 0;
        long long b = 1;
        long long c = 0;
        for(int i = 2;i <= n;i++)
        {
            c = (a + b) % 1000000007;
            a = b;
            b = c;  
        }
        return (int)c;
    }
};
```