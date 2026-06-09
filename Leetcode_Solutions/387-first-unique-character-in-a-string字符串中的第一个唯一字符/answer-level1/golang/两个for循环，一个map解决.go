### 解题思路

1，建立一个字符为`key`，出现次数为`int`类型的`map`；  
2，第一次循环，记录字符串中每个字符出现的次数；  
3，第二次循环，找出`index`。

### 代码

```golang
func firstUniqChar(s string) int {
    // build hash map : character and how often it appears
    cmap := make(map[byte]int)
    for i:=0;i<len(s);i++ {
        c := s[i]
        cmap[c] = cmap[c] + 1
    }

    // find the index
    for i:=0;i<len(s);i++ {
        if cmap[s[i]] == 1 {
            return i
        }
    }

    return -1
}
```