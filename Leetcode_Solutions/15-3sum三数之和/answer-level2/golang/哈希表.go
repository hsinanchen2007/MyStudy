记录数组中各个数字出现的次数，使用两个slice分别保存正数和负数，然后两层循环遍历数组，找到所有结果。
```
func threeSum(nums []int) [][]int {
    res := [][]int{}
    maps := make(map[int]int)
    for _, num := range nums {
        if maps[num] > 0 {
            maps[num] += 1
        } else {
            maps[num] = 1
        }
    }
    if maps[0] > 2 {
        res = append(res, []int{0, 0, 0})
    }
    nums1 := []int{}
    nums2 := []int{}
    for num := range maps {
        if num > 0 {
            nums1 = append(nums1, num)
        }
        if num < 0 {
            nums2 = append(nums2, num)
        }
    }
    for _, a := range nums1 {
        for _, b := range nums2 {
            c := 0 - a - b
            if maps[c] > 0 {
                if c == a && maps[c] > 1 {
                    res = append(res, []int{a, b, c})
                } else if c == b && maps[c] > 1 {
                    res = append(res, []int{a, b, c})
                } else if c > a || c < b || c == 0 {
                    res =append(res, []int{a, b, c})
                }
            }
        }
    }
    return res
}
```
