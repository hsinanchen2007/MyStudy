### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0) return 0;
        if (num & (num - 1)) return 0;
        if (num & 0x2aaaaaaa) return 0; //这个十六进制数为0010 1010 1010 1010 1010 1010 1010 1010
        //4的幂一定是奇数最高位为1 其余为0
        return 1;
    }
};
```