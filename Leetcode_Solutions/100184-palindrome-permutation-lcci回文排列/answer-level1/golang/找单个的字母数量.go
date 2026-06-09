### 解题思路
查找落单的字母，如果落单的字母>1,肯定不是回文字

### 代码

```golang
func canPermutePalindrome(s string) bool {
    
    smp:=map[rune]int{}
    for _,v:=range s{
        smp[v]++
        if smp[v]%2==0{
            delete(smp,v)
        }
    }
    if len(smp)>1{
        return false
    }
    return true
}
```