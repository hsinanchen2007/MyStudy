![image.png](https://pic.leetcode-cn.com/68652fb3632e519f15ef7b94e65b1eb8caaea3e3b63999edb258ae0b730f8cf0-image.png)


### 解题思路

32位整数的最后一位是2的31次方，第一位是2的0次方。

通过` & 0x1`的方式判断最后一位是否为1，如果为1，通过pow进行计算。

然后n右移一位，count减1


### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int count = 31;
    while ( n != 0){
        // 判断最后一位是否为0
        if ( n & 0x1 ) {
            res = res + pow(2, count);
        } 
        n = n >> 1; //每次右移一位
        count = count -1;

    }

    return res;
    
} 
```

上面的pow操作还可以简化成左移, 也就是每次取出原来数字的最后一位二进制，加入到结果中，左移一位。

代码还可以更加简洁

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int count = 32;
    while ( count-- > 0){

        res <<= 1;
        res += (n & 0x1);
        n >>= 1;

    }

    return res;
    
}
```