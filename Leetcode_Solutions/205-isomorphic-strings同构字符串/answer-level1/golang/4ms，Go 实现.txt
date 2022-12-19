
![image.png](https://pic.leetcode-cn.com/7c39c1174d56d422422c79e6cc5461eb4a4c563c9454f680f515a5b2ef585468-image.png)

方法一：借助哈希表 k-v 生成模式串（536ms）
```
func getPattern(s string) string {     // 获得该字符串的模式串
    hash := make(map[rune]string)
    cnt := 0
    pattern := ""
    for _,x:= range s {
        if _,ok := hash[x]; !ok {   // 没出现过
            hash[x] = strconv.Itoa(int(cnt))
            cnt++
        }
        pattern += hash[x]
    }
    return pattern
}

func isIsomorphic(s string, t string) bool {
    p1 := getPattern(s)
    p2 := getPattern(t)
    if p1 == p2 {
        return true
    }
    return false
}
```

方法二：字符串查找（4ms）

遍历两个字符串，查找当前字符出现在后续字符串中的位置，如果是同构字符串，每个字符出现的位置是相同的。


这个方法一开始没想到，看了评论区才晓得，代码比较短而精巧，是巧妙的方法。
```
func isIsomorphic(s string, t string) bool {
    for i:=0; i<len(s); i++ {
        if strings.IndexByte(s[i+1:], s[i]) != strings.IndexByte(t[i+1:], t[i]) {
            return false
        }
    }
    return true
}
```