# 191. 位1的个数
**思路：**
1. 将原始数据n每次移动i位，再和0x00000001按位与去除其他位数；
2. 如果这个结果不为0，即为真，那么该位就是1，结果自增1。

```
int hammingWeight(uint32_t n) {
    int sum = 0;
    for(int i = 0; i < 32; ++i)
    	if( (n>>i)&0x00000001 )
    		++sum;
    return sum;
}
```


