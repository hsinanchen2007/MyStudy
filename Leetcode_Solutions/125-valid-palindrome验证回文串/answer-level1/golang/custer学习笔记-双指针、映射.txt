学习自大佬[@jyd](/u/jyd/)

# 双指针
- 两个指针，一个指针从头进行，一个指针从尾部进行。
- 依次判断两个指针的字符是否相等，同时要跳过非法字符。
- 需要注意的是，两个指针不用从头到尾遍历，当两个指针相遇的时候就意味着这个字符串是回文串了。
- 还需要注意的是 'A' == 'a' ，也就是大写字母和小写字母是相同的。

Two Pointers Time Complexity: O(n) Space Complexity: O(1)

```go
func isPalindrome(s string) bool {
  s = strings.ToLower(s) // 统一转为小写
  str := []rune(s)
  i, j := 0, len(str)-1
  for i < j {
    // 跳过非法字符
    for !isAlphanumeric(str[i]) {
      i++
      if i == len(str) {
        return true
      }
    }
    for !isAlphanumeric(str[j]) {
      j--
    }
    if s[i] != s[j] {
      return false
    }
    i++
    j--
  }
  return true
}

func isAlphanumeric(c rune) bool {
  if 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9' {
    return true
  }
  return false
}
```

# 映射
上边为了处理大小写字母的问题，首先全部统一为了小写。

为了找出非法字符，每次都需要判断一下该字符是否在合法范围内。

这里用一个技巧，
- 把 '0' 到 '10' 映射到 1 到 10，
- 'a' 到 'z' 映射到 11 到 36 ，
- 'A'到 'Z' 也映射到 11 到 36 。

然后把所有数字和字母用一个 char 数组存起来，没存的字符就默认映射到 0 了。

这样只需要判断字符串中每个字母映射过去的数字是否相等，如果是 0 就意味着它是非法字符。

```go
func isPalindrome(s string) bool {
  charMap := make([]rune, 256)
  for i := 0; i < 10; i++ { // 映射 '0' 到 '9'
    charMap[i+'0'] = rune(1 + i) // numeric
  }
  // 映射 'a' 到 'z' 和映射 'A' 到 'Z'
  for i := 0; i < 26; i++ {
    charMap[i+'a'] = rune(11 + i)
    charMap[i+'A'] = rune(11 + i)
  }

  pChars := []rune(s)
  start, end := 0, len(pChars)-1
  for start < end {
    // 得到映射后的数字
    cS := charMap[pChars[start]]
    cE := charMap[pChars[end]]
    if cS != 0 && cE != 0 {
      if cS != cE {
        return false
      }
      start++
      end--
    } else {
      if cS == 0 {
        start++
      }
      if cE == 0 {
        end--
      }
    }
  }
  return true
}
```

# 双指针

```go
func isPalindrome(s string) bool {
  str := []rune(s)
  i := next_alpha_numeric(str, 0)
  j := prev_alpha_numeric(str, len(str)-1)
  for i <= j {
    if strings.ToLower(string(str[i])) != strings.ToLower(string(str[j])) {
      return false
    }
    i = next_alpha_numeric(str, i+1)
    j = prev_alpha_numeric(str, j-1)
  }
  return true
}

func next_alpha_numeric(s []rune, index int) int {
  for i := index; i < len(s); i++ {
    if isAlphanumeric(s[i]) {
      return i
    }
  }
  return len(s)
}

func prev_alpha_numeric(s []rune, index int) int {
  for i := index; i >= 0; i-- {
    if isAlphanumeric(s[i]) {
      return i
    }
  }
  return -1
}

func isAlphanumeric(c rune) bool {
  if 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9' {
    return true
  }
  return false
}
```