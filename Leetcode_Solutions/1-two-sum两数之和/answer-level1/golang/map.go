### 解题思路
执行用时 :4 ms, 在所有 Go 提交中击败了96.94%的
用户内存消耗 :3.8 MB, 在所有 Go 提交中击败了23.20%的用户
内存消耗很大
### 代码

```golang
func twoSum(nums []int, target int) ( result []int) {
	numsMap := make(map[int] int)
	for index, value := range nums {
		sub := target - value
		if _, ok := numsMap[sub]; ok{
			result = append(result, numsMap[sub])
			result = append(result, index)
			break
		}else {
			numsMap[value] = index
		}
	}

	return
}
```