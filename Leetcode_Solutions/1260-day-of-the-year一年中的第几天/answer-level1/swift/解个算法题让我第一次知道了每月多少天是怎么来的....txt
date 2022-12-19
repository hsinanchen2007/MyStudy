### 解题思路
还行，受益匪浅...

### 代码

```swift
class Solution {
    func dayOfYear(_ date: String) -> Int {
        
        var result = 0
        //切割字符串分别获取年月日
        let dateArr = date.split(separator: "-")
        
        guard let year = Int(dateArr[0]), let month = Int(dateArr[1]), let day = Int(dateArr[2]) else {
            return 0
        }


        //格力高历
        var gregorianCalendar = [31,28,31,30,31,30,31,31,30,31,30,31]
        //计算是否为闰年，如果是闰年，2月有29天
        if (year % 400 == 0 || year % 4 == 0) && year % 100 != 0 {
            
            gregorianCalendar[1] = 29
        }
 
        for index in 0..<month - 1 {
            result += gregorianCalendar[index]
        }
        
        result += day

        return result
    }
}
```