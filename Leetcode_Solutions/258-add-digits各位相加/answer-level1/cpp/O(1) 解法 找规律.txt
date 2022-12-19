当 num = 0 时,  result = 0；
当 num > 0 时: 
    假设 num = n, 结果为 f(n), 那么当 num = n + 1 时，f(n+1) = f(n) + 1 。 
    并且最终结果为个位， 即 1 <= result <=9, 可想 每 9 个数字为一次循环， 即 f(n+1) = （f(n) + 1)%9。
    但 f(n+1) = 0 时， f(n+1) = 0。 

```c++
class Solution {
public:
    int addDigits(int num) {
        if( num == 0  ) return 0;
        int result = num%9;
        return result ==  0 ? 9 : result;
    }
};
```
