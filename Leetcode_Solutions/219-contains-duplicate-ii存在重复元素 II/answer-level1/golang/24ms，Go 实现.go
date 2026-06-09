![image.png](https://pic.leetcode-cn.com/aa88546fdbe1b1b383e25a2bce9e9ee70b0bace25b5bcc8a46c8696755fc460a-image.png)

方法一：朴素方法（700ms）

循环比较每个元素和它后面的 k 个元素，越界部分不比较。如果相等，返回 true；如果始终没找到，返回 false。

这个方法时间复杂度较高。
```
func Min(a,b int) int {
    if a<b {
        return a
    }
    return b
}
func containsNearbyDuplicate(nums []int, k int) bool {
    for i:=0; i<len(nums)-1; i++ {
        for _,x := range nums[i+1:Min(i+1+k,len(nums))] { // 依次比较该元素后面的 k 个元素是否相等。超过数组长度的部分不比较。
            if nums[i] == x {
                return true
            }
        }
    }
    return false
}
```

方法二：先找到相等的元素，然后判断下标之差是否不超过 k（24ms）

找到相等元素的时候再判断
```
func containsNearbyDuplicate(nums []int, k int) bool {
    hash := make(map[int]int)      // hash 表记录出现过的元素
    for i,x := range nums {
        if j,ok := hash[x]; ok && i-j<=k {   // 如果之前出现过，判断下标之差是否不超过 k
            return true
        } 
        hash[x] = i
    }
    return false
}
```
