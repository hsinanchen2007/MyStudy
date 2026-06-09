### 解题思路
学习[@jyd](/u/jyd/)大佬的Golang写法
[大佬的详细分析](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/)

### 知识点：快速幂（二进制的位运算）
### 代码

```golang
func myPow(x float64, n int) float64 {
    if x == 0 {
		return 0
	}
	if n < 0 {
		x, n = 1 / x, -n
	}

	res := float64(1)
	for n > 0 {
		if n & 1 == 1 {  // 取n的二进制表示的最低位
			res *= x
		}
		x *= x
		n >>= 1      // 把n的二进制右移一位 == 去掉n的二进制的最低位
	}

	return res
}
```