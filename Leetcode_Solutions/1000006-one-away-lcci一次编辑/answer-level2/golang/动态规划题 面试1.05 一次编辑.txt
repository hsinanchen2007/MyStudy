### 解题思路
大体分为三种情况：
1. 俩个字符串长度相同，则只要不相同的字符数量小于2，便返回true；否则返回fasle
2. 俩个字符串长度相差大于1，返回fasle
3. 来个字符串长度相差小于2：
    依次填充短字符串的每一个空位，再按1的思路对每个空位进行遍历

### 代码

```golang
func oneEditAway(first string, second string) bool {
    
    flen := len(first)
    slen := len(second)
    // 俩个字符串长度相同
    if flen == slen {
        count := 0
        for i:=0; i<flen; i++ {
            if first[i] != second[i] {
                count++
            }
        }
        return count <= 1
    }

    // 长度相差超过1不行
    if Abs(flen-slen) > 1 {
        return false
    }

    // 长度相差是1的情况
    // first 默认为长度更长的一个
    if flen < slen {
        first, second = second, first
        flen, slen = slen, flen
    }
    for i:=0; i<flen; i++ {
        count := 0
        for j := 0; j<flen; j++ {
            if j < i {
                if first[j] != second[j] {
                    count++
                }
            }
            if j>i {
                if first[j] != second[j-1] {
                    count++
                }
            }
        }
        if count == 0 {
            return true
        }
    }
    return false
}

func Abs(i int) int {
    if i < 0 {
        return -i
    }
    return i
}
```