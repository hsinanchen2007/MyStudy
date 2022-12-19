### 解题思路
先通过二分查找，找到target对应的下标pos（若有多个target，则找到其中一个即可）
然后分别从pos的左侧和右侧依次遍历，找到target的上下边界，并返回。

### 代码
执行用时 :8 ms, 在所有 Go 提交中击败了93.71%的用户
内存消耗 :4.1 MB, 在所有 Go 提交中击败了61.38%的用户
```golang
func searchRange(nums []int, target int) []int {
    if len(nums) == 0 {
        return []int{-1,-1}
    }
    l,r := 0, len(nums)-1
    pos := 0
    for l <= r {
        pos = (l+r)>>1
        if nums[pos] == target {
            break
        }else if nums[pos] > target {
            r = pos-1
        }else{
            l = pos+1
        }
    }
    if nums[pos] != target {
        return []int{-1,-1}
    }
    result := make([]int,2)
    for i := pos; i >= 0; i-- {
        if nums[i] == target {
            result[0] = i
        }else{
            break
        }
    }
    for i := pos; i < len(nums); i++ {
        if nums[i] == target {
            result[1] = i
        }else{
            break
        }
    }
    return result
}
```