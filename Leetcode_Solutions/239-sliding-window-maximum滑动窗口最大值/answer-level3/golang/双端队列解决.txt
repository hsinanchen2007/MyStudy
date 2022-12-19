```
func maxSlidingWindow(nums []int, k int) []int {
    if len(nums)==0||k==0{
        return make([]int,0)
    }   
    window:=make([]int,0,k)
    res:=make([]int,0,len(nums)-k+1)
    for i,v:=range nums{
        if i>=k&&window[0]<=i-k{
            window=window[1:len(window)]
        }
        for len(window)>0&&nums[window[len(window)-1]]<v{
            window=window[0:len(window)-1]
        }
        window=append(window,i)
        if i>=k-1{
            res=append(res,nums[window[0]])
        }
    }
    return res
}
```
