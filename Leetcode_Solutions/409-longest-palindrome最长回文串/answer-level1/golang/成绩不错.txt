![image.png](https://pic.leetcode-cn.com/a87306065a3e2b341e6293d5546e331eab44ea8050818c3628f09f0449e511a9-image.png)
# 思路
1.需要用静态数组来记录计数,比map快.
2.字符串的题目,感觉大部分都要用map.

```
func longestPalindrome(s string) int {
    alen := len(s)
    if alen <= 1 {
        return alen
    }
    sum := 1
    arr := make([]int, 52)
    for i:=0; i<alen; i++ {
        if s[i] >= 97 {
            arr[s[i]-'a']++
        } else {
            arr[s[i]-'A'+26]++
        }
    }
    //fmt.Println(arr)
    for i:=0; i<52; i++{
        sum += arr[i]/2*2
    }
    if sum > alen {
        return alen
    }
    return sum
}
```
