```
func bestSeqAtIndex(height []int, weight []int) int {
    n := len(height)
    if n == 0 {
        return 0
    }
    person := make([][2]int, n)
    for i := range person {
        person[i] = [2]int{height[i], weight[i]}
    }
    sort.Slice(person, func(i, j int) bool {
        if person[i][0] == person[j][0] {
            return person[i][1] < person[j][1]
        }
        return person[i][0] > person[j][0]
    })
    var f []int
    for i := 0; i < n; i++ {
        if len(f) == 0 || person[f[len(f)-1]][0] > person[i][0] && person[f[len(f)-1]][1] > person[i][1] {
            f = append(f, i)
        } else {
            l, r := 0, len(f)-1
            for l < r {
                mid := (l+r)>>1
                if person[f[mid]][0] > person[i][0] && person[f[mid]][1] > person[i][1] {
                    l = mid+1
                } else {
                    r = mid
                }
            }
            f[r] = i
        }
    }
    return len(f)
}

```
