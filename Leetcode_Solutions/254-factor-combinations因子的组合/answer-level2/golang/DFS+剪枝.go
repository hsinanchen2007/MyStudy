### 解题思路
![1.png](https://pic.leetcode-cn.com/02a54d927a4079b55dfd2c88cb7795aa0f4928e0676b86be60c079b09f964185-1.png)
此处撰写解题思路

### 代码

```golang
func getFactors(n int) [][]int {
	result := make([][]int, 0, 4)
	list := make([]int, 0, 2)
	dfsGetFactors(n, &result, list)
	return result
}

func dfsGetFactors(n int, result *[][]int, list []int) {
	if n <= 1 {
		return
	}

	for i:=2;i*i<=n;i++ {
		if len(list) != 0 {
			if i < list[len(list)-1] || n/i < list[len(list)-1] {
				continue
			}
		}

		if n % i == 0 {
			list = append(list, i, n/i)
			list2 := make([]int, len(list))
			copy(list2, list)
			*result = append(*result, list2)
			list = list[:len(list)-1]
			dfsGetFactors(n/i, result, list)
			list = list[:len(list)-1]
		}
	}
}
```