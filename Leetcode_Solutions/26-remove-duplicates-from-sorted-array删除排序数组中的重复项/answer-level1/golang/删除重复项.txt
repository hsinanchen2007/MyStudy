

### 代码

```golang
func removeDuplicates(nums []int) int {
    distinctLen := 0
	for index, value := range nums {
		if index == 0 {
			distinctLen +=1
			continue
		}
		if nums[distinctLen - 1] == value {
			continue
		}
		nums[distinctLen] = value
		distinctLen += 1
	}
	return distinctLen
}
```

###执行结果
![image.png](https://pic.leetcode-cn.com/0dfec08c440a45e89b66f0a701e151778186ea9989bdb71b6823c5b13facc8b4-image.png)
