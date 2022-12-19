![lc-offer15.png](https://pic.leetcode-cn.com/9820e7d2f57e22e61771a599c012ab8de0a7c5e7b4539d48a10adb46e15e9f14-lc-offer15.png)

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint8_t count = 0;      // 1最多就32个，所以用8位整数记录就可以了
        while(n){
            if((char)n & true)     // 比较最后一位是否为0
                ++count;
            n = n >> 1;     // 按位右移，准备比较下一位
        }

        return count;
    }
};
```

其中：if((char)n & true)，只需要按位与最后一个字节。由于小端法存储的原因，(char)n得到的就是最后一个字节；true字面值本身是一个字节，值为1，二进制为0000 0001，所以用与&运算，高7位一定是0，最后一位的结果取决于此时n的最后一位。
