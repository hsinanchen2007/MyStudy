### 解题思路
此处撰写解题思路

### 代码

```golang
func removeElement(nums []int, val int) int {
    i := 0
    for i < len(nums) {
        for nums[i] == val {
			if i+1 == len(nums) {
				return len(nums[:i])	
			} 
            nums = append(nums[:i], nums[i+1:]...)
        }
        i = i+1
	}
	fmt.Println(nums)
    return len(nums)
}
```

0ms 击败100%，吃鲸，第一次...