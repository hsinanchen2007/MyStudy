### 解题思路
map 去重

### 代码

```golang
func canConstruct(ransomNote string, magazine string) bool {
    hm := map[rune]int{}
    for _,r :=range magazine{
        if v,ok := hm[r];ok{
            v++
            hm[r] = v
        } else{
            hm[r] = 1
        }
    }

    for _,r :=range ransomNote{
        if v,ok := hm[r];ok{
            if v == 0{
                return false
            }
            v--
            hm[r] = v
        } else{
            return false
        }
    }
    return true
}
```