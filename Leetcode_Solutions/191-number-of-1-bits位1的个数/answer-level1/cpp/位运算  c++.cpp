### 解题思路
循环进行以下操作：
    1让二进制n与二进制数1求交，
        （1）若n的二进制个位为1，则返回1
        （2）若n的二进制个位为0,则返回0
    2二进制n右移一位（对应十进制除2操作）
举例： n=5   对应二进制为101    
与1求交，得1，res=1；   右移，n为2，对应二进制为10, 与1求交，得1， res=2;    右移，n=0，结束。
### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res += (n&1);
            n >>= 1;
        }
        return res;
    }
};
```