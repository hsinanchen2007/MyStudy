双指针
```
func reverseOnlyLetters(S string) string {
    temp := []byte(S)
    flagI, flagJ :=  false, false
    for i, j := 0, len(temp)-1; i < j;{
        if temp[i]>='A' && temp[i]<='Z' || temp[i]>='a' && temp[i]<='z'{
            flagI = true
        }else{
            flagI = false
            i++
        }
        if temp[j]>='A' && temp[j]<='Z' || temp[j]>='a' && temp[j]<='z'{
            flagJ = true
        }else{
            flagI = false
            j--
        }
        if flagI && flagJ{
            temp[i],temp[j] = temp[j],temp[i]
            i++
            j--
        }
        
    }
    return string(temp)
}
```

![image.png](https://pic.leetcode-cn.com/e34866f0bc3120d490c0507ad74bceef15fa073bb81db9a85d3e15c76e612768-image.png)