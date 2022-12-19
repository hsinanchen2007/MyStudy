解题思路：
1.储存对应的值，使用map
2.使用长度进行判断。

```
func romanToInt(s string) int {
    //分别利用两个map储存罗马数字对应的整数
    specialRomeDigital := map[string]int{"IV":4,"IX":9,"XL":40,"XC":90,"CD":400,"CM":900}
    naturalRomeDigital := map[string]int{"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
    //定义一个结果
    result := 0
    //判断输入字符串的长度，大于等于1才进行判断
    for len(s) >= 1 {
        if len(s) == 1 { //长度等于1的时候为正常
            result += naturalRomeDigital[s]
            return result
        }
        if len(s) > 1 { //长度大于1的时候，进行判断
            chars := s[0:2] //利用切片，取出前两个字符进行判断，是否是特殊罗马数字
            if v, ok := specialRomeDigital[chars]; ok {
                result += v
                s = s[2:]
            } else {  //如果不是，则取出第一个进行正常罗马数字的选取
                result += naturalRomeDigital[string(s[0])]
                s = s[1:]  //再进行切片
            }
        }
    }
    if result > 3999 || result < 1 {
        return -1
    }
    return result
}
```
