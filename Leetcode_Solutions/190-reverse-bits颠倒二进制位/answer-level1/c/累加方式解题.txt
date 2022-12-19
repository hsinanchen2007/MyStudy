### 解题思路
按位取，直接位移有一个问题就是原输入末尾连续0的话，位移的时候无法还原多个0
因此使用按位计算值，直接累加的方式。

### 代码

```c
uint32_t reverseBits(uint32_t n) {
   uint32_t output = 0;
   int i = 0;
   for (i = 0; i < 32; i++) {
       char a = n & 0x01;
       if (a == 1) {
           output += (uint64_t)1 << (31 - i);
       }
       n = n >> 1;
   } 
   return output;
}
```