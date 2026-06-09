### 解题思路
看到颠倒二进制这个题目，二进制！首先想到位操作符！
1&n用于检查n的最后一位是否为1；
若为1则ones+=1，若为0则one+=0；
用z来记录ones的大小；（因为ones左移位循环到最后会多移一次，设想最后一次循环ones末位加上了n的首位，此时ones再移位就超出了32为的限制，会出错。此处用z记录ones，避开了ones在循环中的左移位。）
然后左移位；（这样就相当于从n的末位一个一个拿出数，推进z中）
其实思路有一点像从一个栈中依次取出最外端的值，填入另一个栈中。
注意：LeetCode不支持负值左移，所以要ones和z设置为无符号整型。

### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t y=0;
        unsigned int ones=0;
        unsigned int z=0;
        for(int i=0;i<32;i++)
        {
            ones+=(1&n);
            z=ones;
            ones<<=1;
            n>>=1;
        }
        y=(z);
        return y;
    }
};
```