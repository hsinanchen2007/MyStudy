### 解题思路
前后交换

### 代码

```golang
func reverseString(s []byte)  {
  sLen := len(s)
  for i:=0; i< sLen/2; i++{
    s[i],s[sLen-1-i] = s[sLen-1-i],s[i]
  }
}
```