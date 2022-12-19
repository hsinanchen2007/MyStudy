```go
func shortestSeq(big []int, small []int) []int {
    left, right := 0, 0
    l, r := 0, 0
    length := 1 << 31 - 1
    match := 0

    smallMap := make(map[int]int)
    bigsubMap := make(map[int]int)

    for _, s := range small {
        smallMap[s]++
    }
    for right < len(big) {
        if time, ok := smallMap[big[right]]; ok {
            bigsubMap[big[right]] ++

            if bigsubMap[big[right]] == time {
                match++
            }
        }

        for match == len(smallMap) {

            if right - left < length {
                l = left
                r = right

                length = right - left
            }

            if _, ok := smallMap[big[left]]; !ok {
                left ++
                continue
            }
            bigsubMap[big[left]] --

            if bigsubMap[big[left]] < smallMap[big[left]] {
                match --
            }

            left ++

        }
        right ++


    }

    if l == 0 && r == 0 {
        return nil
    }

    return []int{l, r}
}

```