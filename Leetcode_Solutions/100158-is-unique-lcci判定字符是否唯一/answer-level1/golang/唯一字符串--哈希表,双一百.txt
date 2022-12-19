### 解题思路
此处撰写解题思路

### 代码

```golang
func isUnique(astr string) bool {
    m := make(map[byte]int,len(astr))

    for i:=0;i<len(astr);i++ {
        m[astr[i]] ++
        if m[astr[i]] > 1 {
            return false
        }
    }

    return true
}
```