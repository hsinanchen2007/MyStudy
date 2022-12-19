### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) int {
    count := make([]int,58)
    for _,c := range s{
        count[c-'A'] += 1
    }
    ans := 0
    for _,x := range count {
        ans += x/2 * 2
        if x%2==1 && ans%2==0 {
            ans++
        }
    }
    return ans
}
```