### 解题思路
首先, 如何计算两个 int 的不同的比特位的个数?
> 即: k = a ^ b 结果中, 1 的比特位的个数. (异或的性质: 相同为0, 不同为1)

题目要求: `(a | b) == c`
那么, 令 `k = (a|b)^c` , 则 k 中比特位为 1 的位置就是需要「位翻转」的位置.

对 k 的每一个比特位扫描, **当且仅当 bit(k,i) == 1 需要翻转**, 这时看 c 的当前比特位:
+ 如果 bit(c,i) == 1, 说明 bit(a|b, i) == 0, 即 bit(a, i) == 0 && bit(b, i) == 0, 只需要对 a 或者 b 进行一次翻转操作.  
+ 如果 bit(c,i) == 0, 说明 bit(a|b, i) == 1, 这时有 2 种情况: bit(a,i), bit(b,i)的其中之一为1; 两者都为1. 如果 bit(a,i) == 1 那么 a 需要翻转; b同理. 只有这样才能保证 bit(a|b,i) = 0.
 

算法复杂度: 时间和空间均为 $O(1)$ .


### 代码

```cpp
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int k = (a | b) ^ c;
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((k >> i) & 0x1)
            {
                if ((c >> i) & 0x1)
                {
                    ans++;
                }
                else
                {
                    ans += (a >> i) & 0x1;
                    ans += (b >> i) & 0x1;
                }
            }
        }
        return ans;
    }
};
```