### 代码

```golang
func findSubstring(s string, words []string) []int {
    r := []int{}

    // s size
    ss := len(s)

    // words size
    ws := len(words)

    if ws == 0 {
        return r
    }

    // single word length
    wl := len(words[0])

    // ignore s="abc", words=["abc", "def"]
    if ws * wl > ss {
        return r
    }

    m1 := map[string]int{}

    // words=["foo", "foo", "bar"]
    // m1:
    //   foo => 2
    //   bar => 1

    for i := 0; i < ws; i++ {
        word := words[i]

        if v, ok := m1[word]; ok {
            m1[word] = v + 1
        } else {
            m1[word] = 1
        }
    }

    // start

    for i := 0; i < ss - ws * wl + 1; i++ {
        m2 := map[string]int{}
        j := i

        for {
            // find out
            if j - i == ws * wl {
                r = append(r, i)
                break
            }

            // a "word"
            w := string(s[j:j + wl])

            // the "word" in m1
            if v1, ok := m1[w]; ok {
                // the word in m2
                if v2, ok := m2[w]; ok {
                    // usage limit reached
                    if v1 == v2 {
                        break
                    }

                    // record usage
                    m2[w] = m2[w] + 1
                } else {
                    // record usage
                    m2[w] = 1
                }
            } else {
                break
            }

            j += wl
        }
    }
    
    return r
}
```