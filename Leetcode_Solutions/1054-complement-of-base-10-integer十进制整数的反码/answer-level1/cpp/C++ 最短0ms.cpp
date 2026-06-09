### 解题思路
使用bitCount计算N共有多少二进制位，然后再一位位地与1异或运算就行了
![image.png](https://pic.leetcode-cn.com/afbaef9f4d5177ee99f5c812c401fc7143f93d3b574f02f8bb268f3c03ed5e12-image.png)

### 代码

```cpp
class Solution {
public:
    int bitwiseComplement(int N)
    {
        int one = 1;
        int bit = bitCount(N);
        for (int i = 0; i < bit; i++)
        {
            N ^= one;
            one <<= 1;
        }
        return N;
    }
    int bitCount(int n)
    {
        if (n == 0) return 1;
        int cnt = 0;
        while (n)
        {
            cnt++;
            n >>= 1;
        }
        return cnt;
    }
};
```