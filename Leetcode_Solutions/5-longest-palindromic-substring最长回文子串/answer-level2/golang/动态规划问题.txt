### 解题思路
* 动态规划解题，创建二维切片isPal,isPal[i][j]表示s[i:j+1]是回文串，此时最小子结构为
$$
isPal[i][j] = true if isPal[i+1][j-1] and s[i]==s[j]
$$
* 二维切片要事先创建，因为遍历是从二维切片的对角线往右上走的。
```go
// i表示子串的间隔，j表示第几次遍历
for i:=0;i<len;i++{
  for j:=0;i+j<len;j++{
    isPal[j][j+i]
  }
}
```


### 代码

```golang
func longestPalindrome(s string) string {
  sLen := len(s)
  var isPal [][]bool
  for i:=0;i<sLen;i++{
    tmp := make([]bool,sLen+1)
    isPal = append(isPal,tmp)
  }
  maxLen,maxStr := 0,""
  for i:=0;i<sLen;i++ {
    for j:=0;i+j<sLen;j++{
      if j==j+i{
        isPal[j][j+i] = true
      }else if j == j+i-1{
        if s[j]==s[j+i]{
          isPal[j][j+i]=true
        }
      }else{
        if isPal[j+1][j+i-1] && s[j]==s[j+i]{
          isPal[j][j+i]=true
        }
      }
      if isPal[j][j+i] && i + 1 > maxLen{
        maxLen = i+1
        maxStr = s[j:j+i+1]
      }
    }
  }
  return maxStr
}
```