![image.png](https://pic.leetcode-cn.com/3672ad92eb9eddb46bd8e296cbded5c7b9124a267e1621bfee4ccf7b6e9a0621-image.png)


### 代码

```golang
func insert(intervals [][]int, newInterval []int) [][]int {
    r := [][]int{}
    s := [][]int{}
    l := len(intervals)

    if l == 0 {
        return append(r, newInterval)
    }

    // append to tail of slice
    if intervals[l - 1][0] < newInterval[0] {
        s = append(intervals, newInterval)
    } else {
    // insert `newInterval` to `intervals`
        for i := 0; i < l; i++ {
            a, b := intervals[i][0], intervals[i][1]

            if newInterval[0] == a {
                if b < newInterval[1] {
                    intervals[i][1] = newInterval[1]
                }

                s = intervals
                break
            }

            if newInterval[0] < a {
                s = append(s, []int{newInterval[0], newInterval[1]})
                s = append(s, intervals[i:]...)
                break
            }

            s = append(s, intervals[i])
        }
    }

    // process slice
    for i := 0; i < len(s); i++ {
        a, b := s[i][0], s[i][1]
        
        if len(r) == 0 {
            r = append(r, []int{a, b})
            continue
        }

        last := r[len(r) - 1]

        if last[0] <= a && a <= last[1]  {
            r[len(r) - 1][1] = max(b, last[1])
        } else {
            r = append(r, s[i])
        }
    }

    return r
}

func max(a, b int) int {
    if a > b {
        return a
    }

    return b
}
```