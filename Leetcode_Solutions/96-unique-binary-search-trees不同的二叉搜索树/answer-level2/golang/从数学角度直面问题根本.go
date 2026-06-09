# 解法一 dp
- 只是由 [95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/) 的 `3个for+1个递归` 的问题 转换成 `2个for + 乘法`的问题
- 递归结果被存于G内，`递归`被消灭
- `2个for` 合并成 `乘法`,`1个for`被消灭
```golang
func numTrees(n int) int {
	G := make([]int, n+1)
	G[0], G[1] = 1, 1
	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			//此处的乘法 等于 95题 的 两个for循环，数学乘法仅仅只是两个for的结果
			G[i] += G[j-1] * G[i-j]
		}
	}
	return G[n]
}
```

# 解法二 卡特兰数公式
- 其实这个公式也只是更进一步，把`2个for + 乘法`的问题继续转换成 `1个for+乘法` 的问题 
```golang
func numTrees(n int) int {
	C := 1
	for i := 0; i < n; i++ {
		C = C * 2 * (2*i + 1) / (i + 2)
	}
	return C
}
```


# 会不会还有`只有一个乘法的问题`？？？？
[github](https://github.com/temporaries/leetcode)
