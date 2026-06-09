![image.png](https://pic.leetcode-cn.com/aa59fc67afd8b45018692fc1fb2e132c9454189900f4e46eb80764a511def6c3-image.png)

头尾指针的双向遍历

代码：
```
func isPalindrome(s string) bool {
    s = strings.ToLower(s)  // 字母转换为小写
    i,j := 0,len(s)-1
    for i<j {
        if !('a'<=s[i] && s[i]<='z' || '0'<=s[i] && s[i]<='9') {    // 只处理字母和数字
            i++
            continue
        }
        if !('a'<=s[j] && s[j]<='z' || '0'<=s[j] && s[j]<='9') {
            j--
            continue
        }
        if s[i] != s[j] {
            return false
        }
        i++
        j--
    }
    return true
}
```