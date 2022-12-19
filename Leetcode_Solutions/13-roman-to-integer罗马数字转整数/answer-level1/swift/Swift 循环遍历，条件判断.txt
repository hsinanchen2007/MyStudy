> 写法有点无脑、暴力

```
class Solution {
    func romanToInt(_ s: String) -> Int {
        let romanIntDic: [Character : Int] = [
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000
        ]
        
        var lastC: Character = "_"// 初始化必须要一个字符
        var total = 0
        for charator in s {
            let tmpInt = romanIntDic[charator]
            // 遍历开始，先叠加
            total = total + (tmpInt ?? 0)
            if ((lastC == "I" && (charator == "V" || charator == "X")) ||
                (lastC == "X" && (charator == "L" || charator == "C")) ||
                (lastC == "C" && (charator == "D" || charator == "M"))){
                // 判断后，再减去
                total = total - romanIntDic[lastC]! * 2
            }
            
            lastC = charator
        }
        return total
    }
}
```
