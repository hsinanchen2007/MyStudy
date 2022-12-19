### 解题思路
奇葩思路，1 到 n 的总和是 (1+n)*n/2，现在假设少了一个 y 多了一个 x，总和假设为 total
上面的几个参数满足: (1+n)*n/2 - y + x = total
找到 x 很容易，例如 map 来定位，排序再定位都可以，而 y 完全可以通过数学公式计算出来哇

### 代码

```golang
func findErrorNums(nums []int) []int {
	m := make(map[int]int)
	n := len(nums)

	var x int
	var total int

	for i := 0; i < n; i++ {
		if _, ok := m[nums[i]]; ok {
			x = nums[i]
		}
		m[nums[i]] = 1
		total = total + nums[i]
	}

	return []int{x, n * (n+1) / 2 - total + x}
}
```