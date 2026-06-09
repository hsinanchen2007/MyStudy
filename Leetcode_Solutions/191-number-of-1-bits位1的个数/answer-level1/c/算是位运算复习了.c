```
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        uint32_t hole = 1;
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((hole & n) == hole)//按位与运算符，这一位同为1则表达式结果为1。
                count++;
            hole <<= 1;//左移一位。
        }
        return count;
    }
};
```
0ms，8.1mb，试了几题，直接对位进行操作确实快，参考了190题，
感觉自己在位操作这部分好菜，如果不是颠倒二进制位那题给的灵感，根本想不起来可以做。