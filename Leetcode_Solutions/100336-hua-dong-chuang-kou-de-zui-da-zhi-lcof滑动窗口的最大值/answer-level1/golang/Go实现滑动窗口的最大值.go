

```golang
func maxSlidingWindow(nums []int, k int) []int {
    if len(nums)==0 || len(nums)<k || k <= 0{
        return nil
    }
    queue,res := []int{},[]int{}
    for i := range nums{
        for i>0 && len(queue)>0 && nums[i]>queue[len(queue)-1]{
            queue = queue[:len(queue)-1]
        }
        queue = append(queue,nums[i])
        if i>=k && nums[i-k]== queue[0]{
            queue =queue[1:]
        }
        if i>=k-1{
            res = append(res,queue[0])
        }
    }
    return res
}
```