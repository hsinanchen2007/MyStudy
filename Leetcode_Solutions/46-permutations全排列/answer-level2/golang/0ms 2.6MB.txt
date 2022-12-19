![image.png](https://pic.leetcode-cn.com/3b5d3cfa1ff1ceb7372eee8cadbb50852c319691f42d6ad91aeacd499ca7c8ab-image.png)

### 解题思路
递归

### 代码

```golang
func permute(nums []int) [][]int {
    var total [][]int
    quan(nums,0,&total)
    return total
}

func quan(nums[]int,idx int,total *[][]int){
    if idx == len(nums)-1{
        n := make([]int,len(nums))
        copy(n,nums)
        (*total) = append((*total),n)
        return
    }
    for i:=idx;i<len(nums);i++{
        nums[i],nums[idx] = nums[idx],nums[i]
        quan(nums,idx+1,total)
        nums[i],nums[idx] = nums[idx],nums[i]
    }
}
```