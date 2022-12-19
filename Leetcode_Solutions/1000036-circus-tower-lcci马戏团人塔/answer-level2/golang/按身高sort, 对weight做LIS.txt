### 解题思路
身高不能相同

### 代码

```golang
func bestSeqAtIndex(height []int, weight []int) int {
    n := len(height)
    if n <= 1 { return n }
    h_w := make([][2]int, n)
    for i := 0; i < n; i++ {
        h_w[i][0], h_w[i][1] = height[i], weight[i]
    }

    sort.Slice(h_w, func(i, j int)bool {
        if h_w[i][0] == h_w[j][0] {
            return h_w[i][1] > h_w[j][1]
        }
        return h_w[i][0] < h_w[j][0]
    })

    var id []int
    for i := 0; i < n; i++ {
        if i == 0 || (h_w[id[len(id)-1]][0] < h_w[i][0] && h_w[id[len(id)-1]][1] < h_w[i][1]) {
            id = append(id, i)
        } else {
            l, r := 0, len(id)-1
            for l < r {
                mid := (l+r) >> 1
                if h_w[id[mid]][0] < h_w[i][0] && h_w[id[mid]][1] < h_w[i][1] {
                    l = mid + 1
                } else {
                    r = mid
                }
            }
            id[r] = i
        }
    }
    return len(id)
}
```