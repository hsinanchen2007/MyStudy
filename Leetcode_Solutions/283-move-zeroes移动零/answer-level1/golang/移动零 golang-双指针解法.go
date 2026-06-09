### 解题思路
1、双指针解法，一个指针i负责循环该数组，一个指针j负责标记0的位置，初始值为0
2、循环开始，判断第i个元素是否非0，非0则交换i,j 同时判断i、j  当不相等再交换，是为了减少一次不必要操作
3、如果发生交换，则代表有0，则j需要往前移动

### 代码

```golang
func moveZeroes(nums []int)  {
    if len(nums) == 0 {
		return
	}
    
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
            if i != j {
            nums[i], nums[j] = nums[j], nums[i]
            }
			j++
		}
	}
}
```