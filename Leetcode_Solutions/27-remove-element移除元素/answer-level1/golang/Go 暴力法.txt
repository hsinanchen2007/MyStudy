### 解题思路


### 代码

```golang
func removeElement(nums []int, val int) int {
    for i:=0;i<len(nums);i++{
        if nums[i] == val{
            if i != len(nums)-1{
                nums = append(nums[:i],nums[i+1:]...)
            }else{
                nums = nums[:i]
            }
            // 回溯确认下后挪过来的节点是不是还是这个值
            i--
		}
    }
    return len(nums)
}

```