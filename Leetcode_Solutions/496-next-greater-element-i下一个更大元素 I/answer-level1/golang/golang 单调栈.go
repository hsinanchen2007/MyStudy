```
func nextGreaterElement(nums1 []int, nums2 []int) []int {
    var stack []int
    var m = make(map[int]int)
    for i:=0;i<len(nums2);i++{
        if len(stack)>0{
            for len(stack)>0 && nums2[i] > stack[len(stack)-1] {
                pop := stack[len(stack)-1]
                m[pop] = nums2[i]
                stack = stack[:len(stack)-1]
            }
        }
        stack = append(stack,nums2[i])
    }
    for _,v := range stack{
        m[v] = -1
    }
    var res []int
    for i:=0;i<len(nums1);i++{
        res = append(res,m[nums1[i]])
    }
    return res
}
```
