### 解题思路
不妨想成下楼梯，每次只能下 1阶或者下两阶，多少种方法下到底
这样就比较好理解状态转移过程了。
递归 可以，但是会超出内存限制
所以需要缓存每一阶的计算结果

### 代码

```golang
func climbStairs(n int) int {
	if n == 1 {
		return 1
	} else if n == 2 {
		return 2
	}

	types := make([]int,n)
	types[0] = 1
	types[1] = 2

	for m :=2; m<n ;m++  {
		types[m] = types[m-1]+types[m-2]
	}

	return types[n-1]
}

```