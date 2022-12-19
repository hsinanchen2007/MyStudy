### 解题思路
首先找到最短的字符串, 因为公共前缀不可能比最短的字符串还长. 

因为要找最长的公共前缀, 所以用最短的字符串, 从最长的子串开始遍历, 查找所有的字符串是否含有该前准. 

如果没有, 就用最短的字符串去掉最后一个字符继续进行前缀遍历. 

如果遍历了整个字符串数组发现都含有这个前缀, 则直接返回结果.就是当前用来遍历的最短字符串. 

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    var min = 0
    for i, s := range strs {
        if len(strs[min]) > len(s) {
            min = i
        }
    }
    for i:= len(strs[min]); i> 0 ; i-- {
        for x, s := range strs{
            if strings.HasPrefix(s,strs[min][:i]) {
                if x == len(strs) -1 {
                   return strs[min][:i] 
                }
                continue
            }else {
                break
            }
        }
    }
    return ""
}
```