### 解题思路
谁长剪谁的JJ，剪到一样长为止

### 代码

```golang

func gcdOfStrings(str1 string, str2 string) string {
    len1 := len(str1)
    len2 := len(str2)
    if len2 > len1 {
        str1, str2 = str2, str1
        len1, len2 = len2, len1
    } else if len1 == len2 {
        if str1 == str2 {
            return str1
        }
        return ""
    }
    return check2(str1, str2)
}

func check2(str1 string, str2 string) string {

    for {
        len1 := len(str1)
        len2 := len(str2)
        if len1 == len2 {
            if str1 == str2 {
                return str1
            } else {
                return ""
            }
        } else if str1[:len2] == str2 {
            str1 = str1[len2:]
            swapStr(&str1, &str2)
        } else {
            return ""
        }
    }

}

func swapStr(str1 *string, str2 *string) {
    len1 := len(*str1)
    len2 := len(*str2)
    if len2 > len1 {
        *str1, *str2 = *str2, *str1
    }
}

```

![image.png](https://pic.leetcode-cn.com/71f6ba9f8e99b539ad978f6caa8705bdb4acea08bb4593f22aaaf9539c05fbda-image.png)
