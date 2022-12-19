### 解题思路
此处撰写解题思路
![11111.png](https://pic.leetcode-cn.com/fb60ed7ba40a67772d3af95ff5fde628a66c9c2a09b32fca2b1687a6d5065c3d-11111.png)

### 代码

```golang
/*
解题思路：
算法一：最笨的办法，复杂度是 O（n^2）
算法二：参照golang 中strings.Index(str, subStr), 使用了Rabin算法（滚动hash）
    1、go中strings.Index(str, subStr)实现原理是，将subStr求对应的hash值 ，复杂度是O（n）
    2、实现hash = hash * RK + unit32(s[i]) RK 是个常量用来计算hash，滚动hash可以网上学习一下
*/
func strStr1(str string, subStr string) int {
    if subStr == "" || str == subStr {
        return 0
    }
    for i:=0; i< len(str)-len(subStr)+1; i++ {
        if str[i:len(subStr)+i] == subStr {
            return i
        }
    }
    return -1
}
// 算法二 
const RK = 100
func strStr(str string, subStr string) int {
    if len(str) < len(subStr) {
        return -1
    }
    hash, pow := hashStr(subStr) //子串的hash
    n := len(subStr)
    var h uint32
    for i := 0; i < n; i++ {
        h = h * RK + uint32(str[i]) //母串前n的hash
    }
    if h == hash && str[:n] == subStr {
        return 0
    }
    for i := n ;i< len(str); {
        h -= pow * uint32(str[i-n]) // 扣掉头部的，窗口长度保持n
        h *= RK
        h += uint32(str[i])
        i++
        if h == hash && str[i-n:i] == subStr {
            return i-n
        }
    }
    return -1
}
func hashStr(sep string) (uint32, uint32) {
    hash := uint32(0)
    for i := 0; i < len(sep); i++ {
        hash = hash*RK + uint32(sep[i])
    }
    var pow uint32 = 1
    for i := 0; i< len(sep)-1; i++ {
        pow = pow * RK
    }
    // s[0]*RK^2 + s[1]*RK + s[2]， 这个pow计算的就是第一个元素 RK^2,
    // 在计算滚动第四个元素的时候，需要把第一个元素踢出,所以提前算出来
    return hash, pow
}
```