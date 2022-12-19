```go []
func twoSum(nums []int, target int) []int {
    m:=make(map[int][]int,len(nums))
    for k,v:=range nums{
        idxs,ok:=m[target-v]
        if ok{
            return []int{idxs[0],k}
            // target-v 的值存在但是不确定是不是同一个 key 值，
            // 后加入 map 的话，找到了就直接返回，找不到就加进 map，
            // 避免了这个问题
        }
         m[v]=append(m[v],k)
    }
    return nil
}
```
执行用时 : 4 ms, 在所有 golang 提交中击败了96.86%的用户
内存消耗 :3.9 MB, 在所有 golang 提交中击败了16.22%的用户
