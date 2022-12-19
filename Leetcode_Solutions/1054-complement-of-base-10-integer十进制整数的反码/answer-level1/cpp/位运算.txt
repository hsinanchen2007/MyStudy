**简单的位运算**

以十进制数9为例，计算出去除前导零后的二制位数为4。

随后只要左移28位，按位取后后再右移28位即可。
```
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        
        int p = 32, num = N;
        while (num)
        {
            p --;
            num = num >> 1;
        }
        
        return ~(N << p) >> p;
    }
};
```