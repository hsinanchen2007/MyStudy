首先对数组排序，因为题目不要求连续子数组，所以排序对结果不影响

- 以 1 3 5 8 9 为例，子数组长度为1是不用考虑。从len - 2开始倒序遍历。（结合图片理解）

![WechatIMG54.jpeg](https://pic.leetcode-cn.com/f78d7a94ecc38570080afff7f31c74ab5b838fb0839584c487befc6995eae1d9-WechatIMG54.jpeg)

-  [8,9]  末尾是9 的有1 个， [8 9]
-  [5,8,9] 末尾是9 的有2个, [5,9] [5,8,9]
-  [3,5,8,9] 末尾是9的有4个。

由此可以得出，idx 相对于idx + 1，数组的数量就是 + pow * 2。在末尾不变的情况下，开头从A[i+1]变成A[i]。所以只需要在上一个结果的基础上，加上 A[i+1] - A[i]

```
func sumSubseqWidths(A []int) int {
	sort.Ints(A)
	ret, sum, p, mod := 0, 0, 1, 1000000007
	for i := len(A) - 2; i >= 0; i-- {
		p = (p * 2) % mod
		sum = (sum * 2 % mod + (p - 1) * (A[i+1] - A[i]) % mod) % mod
		ret = (ret + sum) % mod
	}
	return ret
}
```