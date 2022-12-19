
![image.png](https://pic.leetcode-cn.com/ff95f0928270f6ba0e3fe00459ca3b67750a130e18792c9a711a04b362bb36c2-image.png)

```
func intersection(nums1 []int, nums2 []int) []int {
    hash := make(map[int]bool)
    ans := []int{}
    for _,x := range nums1 {    // 记录 nums1 中出现过的数
        hash[x] = false
    }
    for _,x := range nums2 {
        if isv,ok := hash[x]; ok && !isv {    // 交叉数，在 nums1 中出现过，记录下来
            ans = append(ans, x)
            hash[x] = true
        }
    }
    return ans
}
```