- 回溯+剪枝
- 借助加法原则剪枝
- 不剪枝会超时

```
var noZero map[byte]bool
var visited []bool
var wordss []string
var hash map[byte]int
var bitNum []int
func isSolvable(words []string, result string) bool {
    noZero = make(map[byte]bool)
    visited = make([]bool, 10)
    wordss = append(words,result)
    hash = make(map[byte]int)
    bitNum = make([]int,0)

    diffLen := DiffLen(words,result)
    if diffLen > 1 || diffLen < 0 {
        return false
    }

    str := GetChars()
    if len(str) > 10 {
        return false
    }

    noZero[result[0]] = true
    for _, word := range words {
        noZero[word[0]] = true
    }
    return dfs(str)
}

func dfs(s string) bool {
    for i,bit := range bitNum {
        if bit == len(hash) {   
            if !check(i) {
                return false
            }
            if i == len(bitNum)-1 {
                return true
            }
        }
        if len(hash) < bit {
            break
        }
    }
    for i:=0;i<10;i++ {
        if i==0 && noZero[s[0]] || visited[i]{
            continue
        }
        hash[s[0]] = i
        visited[i] = true
        if dfs(s[1:]) {
            return true
        }
        visited[i]=false
        delete(hash,s[0])
    }
    return false
}

func check(cnt int) bool {
    intArr := make([]int,0)
    for _,word := range wordss {
        pro := 1
        num := 0
        i,j:=len(word)-1,0
        for ;i>=0&&j<=cnt; {
            num += hash[word[i]]*pro
            pro *= 10
            i--
            j++
        }
        intArr = append(intArr, num)
    }
    sum := 0
    for i:=0;i<len(intArr)-1;i++ {
        sum += intArr[i]
    }
    mod := 10
    for i:=0;i<cnt;i++{
        mod *=10
    }
    return sum%mod == intArr[len(intArr)-1]
}

func DiffLen(words []string, result string) int {
    l1 := len(words[0])
    for i:=1;i<len(words);i++ {
        l1 = max(l1,len(words[i]))
    }
    return len(result) - l1
}

func GetChars() string {
    m := make(map[byte]bool)
    arr := make([]byte,0)
    n := len(wordss[len(wordss)-1])
    for i:=0;i<n;i++ {
        for _, word := range wordss {
            idx := len(word)-1-i
            if idx >= 0 {
                ch := word[idx]
                if !m[ch] {
                    arr = append(arr,ch)
                    m[ch] = true
                }
            }
        }
        bitNum = append(bitNum, len(arr))
    }
    return string(arr)
}

func max(a,b int) int {
    if a > b {
        return a
    }
    return b
}
```
