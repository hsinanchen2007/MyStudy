
```
func maxSlidingWindow(nums []int, k int) []int {
    if nums == nil || len(nums) == 0 || k <= 0 {
        return nil
    }
    
    var window, res = make([]int,0), make([]int,0)
    
    for i, v := range nums{
        //移动窗口
        if i >=k && window[0] <= i-k{
            window = window[1:]
        }
        
        //过滤窗口最大值
        for len(window) > 0 && nums[window[len(window)-1]] <= v {
            window = window[:len(window)-1]
        }
        
        window = append(window, i)
        
        //返回每个窗口结果
        if i >= k-1 {
            res = append(res,nums[window[0]])
        }
    }
    return res
}
```
