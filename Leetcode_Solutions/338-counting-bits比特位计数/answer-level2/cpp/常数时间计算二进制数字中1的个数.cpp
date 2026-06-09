### 解题思路

用一个mask掩码每8位存储1的个数，最后对这个32位整型每8位叠加输出

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i=0;i<=num;i++)
        {
            if(i<=1)
                ret.push_back(i);
            else 
                ret.push_back(countBit(i));
        }
        return ret;
    }
    int countBit(int num)
    {
        int mask=0x01|0x01<<8|0x01<<16|0x01<<24,bits=0;

        bits+=mask&(num>>0);
        bits+=mask&(num>>1);
        bits+=mask&(num>>2);
        bits+=mask&(num>>3);
        bits+=mask&(num>>4);
        bits+=mask&(num>>5);
        bits+=mask&(num>>6);
        bits+=mask&(num>>7);
        return (bits&0xff)+((bits>>8)&0xff)+((bits>>16)&0xff)+((bits>>24)&0xff);
    }
};
```