![image.png](https://pic.leetcode-cn.com/b7b1d51836a5c41ae7f1ba810adbe92d70c2b0b4384c4196fef6d7ae0a93a073-image.png)



```golang
var R []string

func restoreIpAddresses(s string) []string {
    R = []string{}

    S(s, 0, []string{})

    return R
}

func S(s string, i int, nums []string) {
    if len(nums) == 3 {
        if isFine(s[i:len(s)]) {
            nums = append(nums, s[i:len(s)])
            R = append(R, strings.Join(nums, "."))
        }

        return
    }
    
    for j := 0; j < 3; j++ {
        if i + j + 1 <= len(s) && isFine(s[i:i + j + 1]) {
            S(s, i + j + 1, append(nums, s[i:i + j + 1]))
        } else {
            break
        }
    }
}

func isFine(s string) bool {
    l := len(s)

    switch l {
    case 1: return true
    case 2: return s[0:1] != "0"
    case 3: return s[0:1] != "0" && s < "256"
    }

    return false
}
```