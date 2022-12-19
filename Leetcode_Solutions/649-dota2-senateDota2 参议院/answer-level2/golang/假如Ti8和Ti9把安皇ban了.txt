RTRT，别问，问就LGD应该在Ti8胜者组决赛先手把Ana ban了，就没有fy背后的烟火声了...

执行用时 : 0 ms, 在所有 golang 提交中击败了100.00%的用户
内存消耗 : 3.3 MB, 在所有 golang 提交中击败了100.00%的用户

```go
func predictPartyVictory(senate string) string {
    n := len(senate)
    ban := make([]int, n)
    senators := [2]int{0, 0};
    credit := 0
    for _, s := range senate {
        if s == 'R' {
            senators[0]++
        } else if s == 'D' {
            senators[1]++
        }
    }
    for {
        if senators[0] <= 0 {
            return "Dire"
        } else if senators[1] <= 0 {
            return "Radiant"
        }
        for i, s := range senate {
            if s == 'R' {
                if ban[i] == 0 {
                    if credit < 0 {
                        ban[i] = 1
                        senators[0]--
                    }
                    credit++
                }
            } else if s == 'D' {
                if ban[i] == 0 {
                    if credit > 0 {
                        ban[i] = 1
                        senators[1]--
                    }
                    credit--
                }
            }
        }
    }
}
```