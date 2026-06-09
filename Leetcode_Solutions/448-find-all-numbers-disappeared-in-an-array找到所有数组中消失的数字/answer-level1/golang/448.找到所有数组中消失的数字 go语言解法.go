### 解题思路

使用哈希表，遍历数组把出现过的数存在哈希表中。再遍历哈希表，把没有存在哈希表中的数存进数组即可。

### 代码

```golang
func findDisappearedNumbers(nums []int) []int {
	hash := map[int]int{}
	res := []int{}
	for _,i := range nums {
		hash[i] = 1
	}
	for j := 1;j <= len(nums);j++ {
		if hash[j] != 1 {
			res = append(res,j)
		}
	}
	return res
}
```