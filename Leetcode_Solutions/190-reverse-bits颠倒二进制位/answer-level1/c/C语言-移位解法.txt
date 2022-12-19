### 解题思路
利用mask b'1<<31,获取到输入的数二进制表示的最高位，放置到输出的最低位。
重复上述的过程，直到利用mask b'1<<0,获取输入的数二进制表示的最低位，放置到输出的最高位。
思路简单，实现也简单。

这里面唯一一个注意点，就是代码里这一行
uint32_t mask = (uint32_t)1 << 31;

左值1的强制转化不可缺少，因为1会被认为是一个int数，直接右移31位，这个结果是未定义的，因为int可能没有32位长度。
### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t mask = (uint32_t)1 << 31;
    uint32_t temp = 0;

    int i = 31;
    for ( i = 31; i >= 0; i--)
    {
        temp |= (uint32_t)((n & mask) >> i) << (31 - i);
        mask = mask >> 1;
    }

    return temp;
}
```