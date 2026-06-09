![image.png](https://pic.leetcode-cn.com/56e7504bc5dad90cc002c6e71c4e8fc4fc686f56f8e02812a5d67eb930f706ab-image.png)
```go
func intersection(nums1 []int, nums2 []int) []int {
    set := make(map[int]bool)
    res := make([]int, 0)
    for _, v1 := range nums1 {
        set[v1] = true
    }
    for _, v2 := range nums2 {
        if m, ok := set[v2]; ok && m {  //nums2里面包含nums1里的元素
            res = append(res, v2)
            set[v2] = false             //防止重复输出
        }
    }
    return res
}
```


