### 题目
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

### 解题思路
用哈希记录。
或者用数组进行记录，明显数组的性能要好得多，因为数组在判断是否存在时比哈希要快的多。

### 代码

```golang
// func longestPalindrome(s string) int {

//     // 用哈希写
//     if len(s) <= 0 {
//         return 0
//     }
//     maps := make(map[byte]int)
//     ret := 0
//     for i:=0; i<len(s); i++ {
        
//         if  _, ok := maps[s[i]]; ok {
//             maps[s[i]]++
//             if maps[s[i]] % 2 == 0 {
//                 ret += 2
//             }
//         } else {
//             maps[s[i]] = 1
//         }
//     }

//     iindex := 0
//     for _, key := range maps {
//         if key % 2 == 1 {
//             iindex = 1
//             break
//         }
//     }
    
    
//     if iindex % 2 == 1 {
//         return ret + 1
//     }else {
//         return ret 
//     }
// }

func longestPalindrome(s string) int {

    ret := 0
    numsArray := make([]int, 123)
    for i:=0; i<len(s); i++ {
        numsArray[s[i]%123]++
        if numsArray[s[i]%123] % 2 == 0 {
            ret += 2
        }
    }
    index := 0
    for i:= 65; i< 123; i++ {
        if numsArray[i] % 2 == 1 {
            index = 1
            break
        }
    }
    if index == 0 {
        return ret
    } else {
        return ret + 1
    }
    

}
```