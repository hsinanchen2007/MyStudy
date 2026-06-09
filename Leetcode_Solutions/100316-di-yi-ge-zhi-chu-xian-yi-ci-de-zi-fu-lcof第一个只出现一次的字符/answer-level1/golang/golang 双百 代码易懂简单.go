### 解题思路

先遍历一遍字符串，将其出现次数存储在数组中，在按字符串遍历一次，同时按字母查询数组，如果次数为1则返回


### 参考代码

```
func firstUniqChar(s string) byte {
    var list [26]int
    length := len(s)
    for i:=0;i<length;i++ {
        list[s[i]-'a']++
    }
    for i:=0;i<length;i++{
        if list[s[i]-'a'] == 1 {
            return s[i]
        }
    }
    return ' '
}
```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**




