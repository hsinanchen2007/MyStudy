由于题目限制 0 <= A[i] <= 100， 可以比较容易的想到去遍历0到100的数，而不是遍历数组A

- 记录0到100的数组出现的次数
```
num := [101]int{}
for i := 0; i < len(A); i++ {
	num[A[i]]++
}
```

- 我们需要找到3个数相加等于target。我们可以通过数字的顺序i，j找到k。找到i，j，k之后就是简单乘法，如有数字相等，就用排列组合计算。

- 为什么可以用排列组合计算。我们可以考虑把A排序，比如 1 1 1 1 2 2 5 5。那么我们可以找到 1  2 5 三个数字。单个数字每个索引其实都是合法的，那么就是 4 * 2  * 2。 如果target = 3，那么应该是 1 1 1。这就是很显然的3个坑，4个数按顺序去填，c43。

```
func cal(i, j, k int, nums [101]int) int {
	if i == j && j == k {
		num := nums[i]
		return num * (num-1) * (num-2) / (1 * 2 * 3)
	}
	if i == j && j != k {
		return nums[i] * (nums[i] - 1) * nums[k] / 2
	}
	if i != j && j == k {
		return nums[i] * nums[j] * (nums[j] - 1) / 2
	}
	return nums[i] * nums[j] * nums[k]
}
```
完整代码：
```
func threeSumMulti(A []int, target int) int {
	count := 0
	mod := 1000000007
	num := [101]int{}
	for i := 0; i < len(A); i++ {
		num[A[i]]++
	}
	for i := 0; i < len(num); i++ {
		if num[i] == 0 {
			continue
		}
		for j := i; j < len(num); j++ {
			if num[j] == 0 {
				continue
			}
			k := target - i - j
			if k < j {
				break
			}
			if k > 100 || num[k] == 0 {
				continue
			}
			count = (count + cal(i, j, k, num)) % mod
		}
	}
	return count
}

func cal(i, j, k int, nums [101]int) int {
	if i == j && j == k {
		num := nums[i]
		return num * (num-1) * (num-2) / (1 * 2 * 3)
	}
	if i == j && j != k {
		return nums[i] * (nums[i] - 1) * nums[k] / 2
	}
	if i != j && j == k {
		return nums[i] * nums[j] * (nums[j] - 1) / 2
	}
	return nums[i] * nums[j] * nums[k]
}
```