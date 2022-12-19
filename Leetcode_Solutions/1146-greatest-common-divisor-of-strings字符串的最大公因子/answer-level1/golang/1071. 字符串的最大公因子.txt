### 解题思路
辗转相除法：
这条算法基于一个定理：两个正整数a和b（a>b），它们的最大公约数等于a除以b的余数c和b之间的最大公约数。比如10和25，25除以10商2余5,那么10和25的最大公约数，等同于10和5的最大公约数。

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {

    if str1+str2 != str2+str1 {
        return ""
    }
    return str1[0:gcd(len(str1), len(str2))]

}

func gcd(x, y int) int {

    if x > y {
        if x % y == 0 {
            return y
        }else{
            return gcd(y, x%y)
        }
    }else {
        if y % x == 0 {
            return x
        }else{
            return gcd(x, y%x)
        }
    }
    
}
```