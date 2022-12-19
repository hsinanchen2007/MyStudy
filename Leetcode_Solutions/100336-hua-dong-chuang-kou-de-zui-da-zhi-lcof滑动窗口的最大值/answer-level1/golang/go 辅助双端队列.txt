### 解题思路

### 代码

```golang
func maxSlidingWindow(nums []int, k int) []int {
    var helper []int
    var res []int
    if len(nums) == 0{
        return res
    }
    //添加元素到辅助队列
    for i := 0; i < k-1; i++{
        helper = appendMaxToHelper(helper, nums[i])
    }
    for i := k-1; i < len(nums); i++{
        helper = appendMaxToHelper(helper, nums[i])
        // helper[0]一定是当前窗口内的最大元素
        res = append(res, helper[0])
        // 滑动一个位置
        helper = helper[1:]
    }  
    return res
}
    
    
func appendMaxToHelper(helper []int, val int) []int{
     if len(helper) == 0{
         helper = append(helper, val)
     } else {
         for i := len(helper)-1; i > -1; i -- {
             if helper[i] < val{
                  helper[i] = val
             } else{
                 break
             }      
         }
         helper = append(helper, val)
        }
    return helper
}
```