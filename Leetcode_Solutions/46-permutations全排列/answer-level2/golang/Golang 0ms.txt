```go
func permute(nums []int) [][]int {
    res := make([][]int, 0)
    backtrack(&res, nums, []int{}, make(map[int]struct{}))
    return res
}

func backtrack(res *[][]int, nums []int, track []int, trackm map[int]struct{}) {
    if len(nums) == len(track) {
        buf := make([]int, len(track))
        copy(buf, track)
        *res = append(*res, buf)
        return
    }
    for _, n := range nums {
        if _, ok := trackm[n]; ok {
            continue
        }
        track = append(track, n)
        trackm[n] = struct{}{}
        backtrack(res, nums, track, trackm)
        track = track[:len(track)-1]
        delete(trackm, n)
    }
}
```