![image.png](https://pic.leetcode-cn.com/73af9b3046b630ffd037802b23e49293b01aa0cf756a39b89d76859b2ef2666b-image.png)

```
//1、 通过卡特兰数递推公式推算 c * 2 * (2*n +1)/ (i+2)
func numTrees(n int) int {
	c := 1
	for i := 0; i < n; i++ {
		c = c * 2 * (2*i + 1) / (i + 2)
	}
	return c
}
```

```
//动态规划
func numTrees(n int) int {
	g := make([]int, n+1)
	g[0] = 1
	g[1] = 1
	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			g[i] += g[j-1] * g[i-j]
		}
	}
	return g[n]
}
```

