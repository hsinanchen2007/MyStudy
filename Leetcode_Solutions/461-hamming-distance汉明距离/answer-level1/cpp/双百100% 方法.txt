### 解题思路
此处撰写解题思路
    //1.两个数字异或之后可以得到 不同二进制位的数字
    //2.计算该数字中1的个数，即是汉明距离
    //计算1的个数时，有几种方法，1：不断和左移的1 进行 与，判断该位是否为1.
    //                        2:  n&(n-1)就是把n最右边的bit 1 位去掉，看能去掉几次，就有几个1位。

### 代码

```cpp
class Solution {
public:
    //1.两个数字异或之后可以得到 不同二进制位的数字
    //2.计算该数字中1的个数，即是汉明距离
    //计算1的个数时，有几种方法，1：不断和左移的1 进行 与，判断该位是否为1.
    //                        2:  n&(n-1)就是把n最右边的bit 1 位去掉，看能去掉几次，就有几个1位。
    int hammingDistance(int x, int y) {
        return countBitNumber(x^y);
    }
    int countBitNumber(int n)
    {
        int count = 0;
        while(n)
        {
            n = (n & n-1);
            ++count;
        }
        return count;
    }
};
```