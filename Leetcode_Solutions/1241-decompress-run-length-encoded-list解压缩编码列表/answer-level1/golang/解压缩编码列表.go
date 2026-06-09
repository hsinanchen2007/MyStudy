### 解题思路
直接看代码吧

### 代码

```golang
func decompressRLElist(nums []int) []int {
	var ret []int
	for i := 1; i < len(nums); {
		for j := 0; j < nums[i-1]; j++ {
			ret = append(ret, nums[i])
		}
		i += 2
	}
	return ret
}
```