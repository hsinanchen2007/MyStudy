### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) string {
        ans :=""
        n := len(s)
        // if n <2 {
        //     return s
        // }
        max := 0
        for i:=0;i<n;i++{
            for j:=i+1;j<=n;j++{
                test := s[i:j]
                tn := j-i+1
                if isPalindromic(test) && tn > max {
                    //fmt.Println(test)
                    ans = test
                    max = tn
                }
            }
        }
        return ans

}

func isPalindromic(s string)bool{
    n := len(s)
    for i:=0;i<n/2;i++{
        if s[i] != s[n-i-1]{
            return false
        } 
    }
    return true
}
```