
![image.png](https://pic.leetcode-cn.com/cb25c39066e932ddabf083dfe78a8272c0b1c09de87f6cc43aca14806d3f984e-image.png)

用 map 实现（44ms）
```
func firstUniqChar(s string) int {  // 遍历两遍字符串
    hash := map[rune]int{}
    for _,x := range s {    // 第一遍遍历字符串，记录每个字符出现次数
        hash[x]++
    }
    for i,x := range s {    // 第二遍遍历字符串，找到第一个不重复的字符
        if hash[x] == 1 {
            return i
        }
    }
    return -1
}
```

用数组实现 hash 表（8ms）

用 map 操作慢了好多……

```
func firstUniqChar(s string) int {  // 遍历两遍字符串
    hash := [26]int{}
    for _,x := range s {    // 第一遍遍历字符串，记录每个字符出现次数
        hash[x-'a']++
    }
    for i,x := range s {    // 第二遍遍历字符串，找到第一个不重复的字符
        if hash[x-'a'] == 1 {
            return i
        }
    }
    return -1
}
```