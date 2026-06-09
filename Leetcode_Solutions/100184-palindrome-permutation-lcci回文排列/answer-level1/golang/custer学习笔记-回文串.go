### 解题思路

[leetcode-409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/solution/custerxue-xi-bi-ji-zui-chang-hui-wen-chuan-by-cust/)

### 代码

```golang
func canPermutePalindrome(s string) bool {
  // 初始化用于计数的数组，因为只有大小写英文字母
  m := make([]int, 256)
  oddNum := 0 // 定义数量是奇数的字符个数
  // 遍历字符串，统计每个字符出现的次数
  for _, c := range s {
    m[c]++
  }
  // 接下来统计字符出现的次数
  for _, cnt := range m {
    if cnt %2 == 1 {
      oddNum++
    }
    if oddNum > 1 {
      return false
    }
  }
  return true
}
```