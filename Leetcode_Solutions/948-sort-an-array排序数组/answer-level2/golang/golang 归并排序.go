### 解题思路
二分法将数组拆分：时间复杂度 O(logn)
每层排序：O(n)
所以，总体时间复杂度为 O(nlogn)

### 代码

```golang
func sortArray(nums []int) []int {
    if len(nums) < 2 {
        return nums
    }
    i := len(nums)/2
    left := sortArray(nums[0:i]) 
    right := sortArray(nums[i:])

    return merge(left, right)
}

func merge(l, r []int) []int {
    i, j := 0, 0
    m, n := len(l), len(r)
    var res []int
    for i < m && j < n {
        if l[i] < r[j] {
            res = append(res, l[i])
            i++
        }else {
            res = append(res, r[j])
            j++
        }
    }
    res = append(res, l[i:]...)
    res = append(res, r[j:]...)

    return res
}
```