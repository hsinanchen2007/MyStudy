
![image.png](https://pic.leetcode-cn.com/bcdf649fa51aa36f46add2f28e22c55906cc169f314cd4de1925dd9e86fd59d3-image.png)

用 hash 表记录出现过的元素
```
func containsDuplicate(nums []int) bool {   // hash 表记录出现过的元素
    hash := make(map[int]bool)
    for _,x := range nums {
        if _,ok := hash[x]; ok {
            return true
        } 
        hash[x] = true
    }
    return false
}
```