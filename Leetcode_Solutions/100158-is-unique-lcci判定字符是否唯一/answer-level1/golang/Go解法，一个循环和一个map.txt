### 解题思路

1，创建一个`map`，byte-bool类型；  
2，从字符串`astr`的开头开始，遇见一个字符，判断`map`里是否存有这个字符，如果没有，就存进`map`中，否则就代表已经存在过了，因此有重复的数字，返回`false`；  
3，最后遍历完整个字符串，返回`true`。  

### 代码

```golang
func isUnique(astr string) bool {
    if len(astr) > 128 {
        return false
    }

    var char_set = make(map[byte]bool)
    for i:=0;i<len(astr);i++ {
        if (char_set[astr[i]]) {
            return false
        }
        char_set[astr[i]] = true
    }
    return true
}
```