### 解题思路
统计各个字符出现的次数，出现次数为偶数的字符都算到回文数量中，奇数的次数减1，加到回文数量中。最后加1

### 代码

```golang
func longestPalindrome(s string) int {
    var m =make(map[rune]int)
    var sum int
    var flag bool = false
  for _,x:=range s {
      m[x] = strings.Count(s,string(x))
  }

  for _,v:=range m {
    if v%2==0 {
        sum +=v
    }else {
        sum+=v-1
        flag = true
    }

  }
  if flag {
     sum++
     return sum
  }else{
      return sum
  }

}
```