# 155 - 96 不同的二叉搜索树

## 题目

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

> 输入: 3
> 输出: 5
> 解释:
> 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
>
>    1         3     3      2      1
>     \       /     /      / \      \
>      3     2     1      1   3      2
>     /     /       \                 \
>    2     1         2                 3

## 解答

### 动态规划

> https://leetcode-cn.com/problems/unique-binary-search-trees/solution/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/

- 设n个节点存在二叉排序树的个数是G(n)
- 设f(i)为以i为根的二叉搜索树的个数

那么$G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)$

 那么$f(i)=G(i-1)*G(n-1)$

因为是二叉搜索树，左边的子节点，都要比$i$小，共有$i-1$个；右边子节点，都要比$i$大，共$n-i$个

所以带入得

$G(n)=G(0)∗G(n−1)+G(1)∗G(n−2)+...+G(n−1)∗G(0)$

```python
class Solution:
    def numTrees(self, n: int) -> int:
        g = [0]*(n+1)
        g[0] = g[1] = 1
        for i in range(2, n+1):
            for j in range(1, i+1):
                g[i] += g[j-1]*g[i-j]
        return g[n]
```

> Runtime: 24 ms, faster than 96.30% of Python3 online submissions for Unique Binary Search Trees.
>
> Memory Usage: 12.6 MB, less than 100.00% of Python3 online submissions for Unique Binary Search Trees.

```js
var numTrees = function(n) {
  let g = new Array(n + 1).fill(0)
  g[0] = g[1] = 1
  for (let i = 2; i < n + 1; i++) {
    for (let j = 1; j < i + 1; j++) {
      g[i] += g[j - 1] * g[i - j]
    }
  }
  console.log("g", g[n])
  return g[n]
};
```

> Runtime: 56 ms, faster than 53.22% of JavaScript online submissions for Unique Binary Search Trees.
>
> Memory Usage: 33.9 MB, less than 33.33% of JavaScript online submissions for Unique Binary Search Trees.

```go
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

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Unique Binary Search Trees.
>
> Memory Usage: 2 MB, less than 100.00% of Go online submissions for Unique Binary Search Trees.

### 卡塔兰数

简言之有个公式可以算出来这个
$$
c_0=1,
c_{n+1}=\frac{2(2n+1)}{n+2}*c_n
$$

```python
class Solution:
    def numTrees(self, n: int) -> int:
        c = 1
        for i in range(0, n):
            c = c*2*(2*i+1)/(i+2)
        return int(c)
```

> Runtime: 24 ms, faster than 96.30% of Python3 online submissions for Unique Binary Search Trees.
>
> Memory Usage: 12.8 MB, less than 100.00% of Python3 online submissions for Unique Binary Search Trees.

```go
func numTrees(n int) int {
	c := 1
	for i := 0; i < n; i++ {
		c = c * 2 * (2*i + 1) / (i + 2)
	}
	return c
}
```

> Runtime: 0 ms, faster than 100.00% of Go online submissions for Unique Binary Search Trees.
>
> Memory Usage: 2 MB, less than 100.00% of Go online submissions for Unique Binary Search Trees.

```js
var numTrees = function(n) {
  let c = 1
  for (let i = 0; i < n; i++) {
    c = c * 2 * (2 * i + 1) / (i + 2)
  }
  return c
};
```

> Runtime: 48 ms, faster than 91.71% of JavaScript online submissions for Unique Binary Search Trees.
>
> Memory Usage: 33.7 MB, less than 66.67% of JavaScript online submissions for Unique Binary Search Trees.