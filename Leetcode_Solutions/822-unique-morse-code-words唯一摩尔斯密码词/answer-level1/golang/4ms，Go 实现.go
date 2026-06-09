
![image.png](https://pic.leetcode-cn.com/bbed960b9fba18195c540827bf9bae71ade781df8f0bdf496ecc6611f1486e63-image.png)

```
func uniqueMorseRepresentations(words []string) int {
    table := []string{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}
    hash := map[string]bool{}
    cnt := 0
    for _,w := range words {
        t := ""
        for _,x := range w {
            t += table[x-'a']
        }
        if !hash[t] {
            cnt++
            hash[t] = true
        }
    }
    return cnt
}
```