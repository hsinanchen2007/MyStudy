### 解题思路
此处撰写解题思路
有点耗时，再研究，看看能不能优化一下
### 代码

```golang
func numMatchingSubseq(S string, words []string) int {

    
   
    count := 0
    for i := 0; i < len(words); i++ {
        slow := 0
        str := words[i]
        if len(str) > len(S) {
            continue
        }else {
            for fast := 0; fast < len(S); fast++ {
                // fmt.Println("slow == ", slow)
                // fmt.Println(string(str[slow]))
                if str[slow] == S[fast]{
                    slow++
                    if slow == len(str) {
                        count++
                        break
                    }
                }
            } 
        }
    }
    return count
}
```