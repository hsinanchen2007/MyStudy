```
func minEatingSpeed(piles []int, H int) int {
    l, r := 1, 0
    for i := 0; i < len(piles); i++ {           //返回最大的香蕉数
        if piles[i] > r {
            r = piles[i]
        }
    }
    for l < r {
        mid := (l + r) / 2
        tmp := 0
        for i := 0; i < len(piles); i++ {
            tmp += (piles[i]-1) / mid + 1
        }
        if tmp > H {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return l
}
```
