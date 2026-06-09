### 解题思路
直接暴力即可

![image.png](https://pic.leetcode-cn.com/84d11d7be70cddda6e0f9fe42ab1b18e7c4dfee32b16199a19d1623591b054a8-image.png)


### 代码

```c
uint32_t reverseBits(uint32_t n) {
	int i;
    uint32_t rlt = 0;
	for (i = 0; i < 32; i++) {
		rlt = rlt * 2 + n % 2;
		n /= 2;
	}
	return rlt;
}
```