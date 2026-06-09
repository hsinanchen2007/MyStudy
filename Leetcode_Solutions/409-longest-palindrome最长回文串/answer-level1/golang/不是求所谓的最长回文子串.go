### 解题思路
* 认真读题，不是求最长回文子串的长度
* 注意什么时候长度是奇数

### 代码

```golang
func longestPalindrome(s string) int {
  cntHash := make(map[rune]int)
  maxCnt := 0

  for _,val := range s{
    if _,ok := cntHash[val]; ok{
      cntHash[val] += 1
    }else{
      cntHash[val] = 1
    }
  }
  flag := false
  for _,v := range cntHash{
    if v % 2 == 1{
      flag = true
    }
    maxCnt += v / 2 * 2
  }
  if flag {
    maxCnt += 1
  }
  return maxCnt

}
```