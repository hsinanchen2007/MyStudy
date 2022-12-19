### 解题思路
1. 倒叙遍历每个字符
2. 如果当前遍历的字符的值小于上一个字符对应的值，则减去当前字符对应的值（IV=5-1）
3. 如果当前遍历的字符的值大于上一个字符对应的值，则加上当前字符对应的值 (VI=5+1)
4. 每循环遍历一遍，指针向前移动一位，知道整个字符遍历完成

### 代码

```swift
class Solution {
    func romanToInt(_ s: String) -> Int {
        let info: [Character : Int] = ["I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000]
        var sum: Int = 0
        
        let strs = Array(s)
        var idx = s.count - 1;
        var lastValue = 0
        
        while idx >= 0 {
            
           let str = strs[idx]
           let value = info[str]!
            
            if value < lastValue {
                sum -= value;
            } else {
                sum += value;
            }
            
            lastValue = value;
            idx -= 1;
        }
        return sum
    }
}
```