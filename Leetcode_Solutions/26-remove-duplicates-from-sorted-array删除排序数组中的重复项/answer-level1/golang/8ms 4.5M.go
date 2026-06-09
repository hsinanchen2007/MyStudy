![image.png](https://pic.leetcode-cn.com/05071e4201206a313df025512c580e17dcd3b2117a4878a5d506058b106101e7-image.png)

### 解题思路
双指针，左边那个指向要填不相同元素的位置，右边那个就找不相同的元素

### 代码

```golang
func removeDuplicates(nums []int) int {
    if len(nums) == 0{
        return 0
    }
    if len(nums) == 1{
        return 1
    }

    left,right := 0,1
    for right< len(nums){
        if nums[left] == nums[right]{
            right++
        }else{
            left++
            nums[left] = nums[right]
            right++
        }
    }

    return left+1
}
```