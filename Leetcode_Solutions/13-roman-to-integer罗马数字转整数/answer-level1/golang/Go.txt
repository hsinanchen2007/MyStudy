### 解题思路
此处撰写解题思路

### 代码

```golang
func romanToInt(s string) int {
    R_dict := map[string]int {
        "I":1,
        "IV":4,
        "V":5,
        "IX":9,
        "X":10,
        "XL":40,
        "L":50,
        "XC":90,
        "C":100,
        "CD":400,
        "D":500,
        "CM":900,
        "M":1000,
    }

    ss := strings.Split(s, "")
    res := 0
    for i := 0; i < len(ss); {
        var temp string
        if i < len(ss)-1 {
            temp = ss[i] + ss[i+1]
        } else {
            temp = ss[i]
        }

        val, found := R_dict[temp]
        if found {
            res += val
            i += 2
        } else {
            res += R_dict[ss[i]]
            i++
        }
    }
    return res
}
```