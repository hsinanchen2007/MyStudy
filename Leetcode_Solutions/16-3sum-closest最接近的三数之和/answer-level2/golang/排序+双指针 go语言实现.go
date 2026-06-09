### 解题思路
排序+双指针

执行用时 : 0 ms, 在所有 golang 提交中击败了100.00%的用户
内存消耗 : 2.7 MB, 在所有 golang 提交中击败了59.14%的用户

+ 记住Abs函数自己写，库里面的形参是float64，强转+浮点运算很慢
+ 我这边Abs没考虑到临界问题，负数比正数多一个

### 代码

```golang
func threeSumClosest(nums []int, target int) int {
    ns := nums
    if !sort.IntsAreSorted(ns) {
        sort.Ints(ns)
    }

    var result = ns[0] + ns[1] + ns[2]
    
    for i, v := range ns {
        
        for left, right := i+1, len(ns) - 1; left < right; {
            sum3 := v + ns[left] + ns[right]
            if sum3 > target {
                right--
            } else if sum3 < target {
                left++
            } else if sum3 == target {
                return target
            }
            if AbsInt(result-target) > AbsInt(sum3-target) {
                result = sum3
            }
        }
    }

    return result
}

func AbsInt(v int) int {
    if v >= 0 {
        return v
    } else {
        return -v
    }
}




/** 
    思路： 
        1. 排序
        2. 双指针， 贪心
        与上题同


*/
```