双map统计两个数组中各个数字出现的频率，然后循环出现少的那个次数加入到结果集中。
```go
func intersect(nums1 []int, nums2 []int) []int {
    var res []int
    m1 := make(map[int]int)                      // 统计num1中各个数字的出现频率
    m2 := make(map[int]int)                      // 统计num2中各个数字出现的频率
    for _, n1 := range nums1 {
        m1[n1] += 1
    }

    for _, n2 := range nums2 {
        m2[n2] += 1
    }
    for k1, v1 := range m1 {
        v2, ok := m2[k1]
        if ok {
            min := int(math.Min(float64(v1), float64(v2)))  // 选定出现次数少的那个，并循环这么多次加入到结果集中
            for min > 0 {
                res = append(res, k1)
                min--
            }
        }
    }
    return res
}
```
![image.png](https://pic.leetcode-cn.com/577c890b31dd91ed32038ed82485497488fd01275625dfa3045d72842e66e21c-image.png)
