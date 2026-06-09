### 解题思路
利用DFA来处理这个问题，然后在进行边界处理的时候注意即可。

### 代码

```swift
class Automation {
    // 初始状态
    private var state = "start"

    // 状态转变表
    private var transformTable: [String : [String]] = [
        "start" : ["start", "signed", "in_number", "end"],
        "signed": ["end", "end", "in_number", "end"],
        "in_number": ["end", "end", "in_number", "end"],
        "end"   : ["end", "end", "end", "end"]
    ]

    // 输出时的符号
    public var sign = 1

    // 在Swift中，Int的默认值是Int64
    // 在本题中，要求的是Int32
    public var result = 0

    // 输入的字符与创建的状态转换表的关系
    private func setState(_ char: Character) -> Int {
        if char.isWhitespace {
            return 0
        }
        if char == "+" || char == "-" {
            return 1
        }
        if char.isNumber {
            return 2
        }

        return 3

    }
    
    // 根据输入的字符来确定状态
    func getNewChar(_ char: Character) {
        state = transformTable[state]![self.setState(char)]

        // 如果改变后的状态是数字
        if state == "in_number" {
            result = result * 10 + Int.init("\(char)")!
            if sign == -1 {
                if -result < Int32.min {
                    result = -Int.init(Int32.min)
                } 
            }
            if sign == 1 {
                if result > Int32.max {
                    result = Int.init(Int32.max)
                } 
            }
            
        }

        // 如果改变后的状态是符号位
        if state == "signed" {
            if char == "-" {
                sign = -1
            }
        }
    }
}


class Solution {
    func strToInt(_ str: String) -> Int {
        // 有穷自动机来表示状态的转换，然后有穷自动机的状态转换
        var automatic = Automation()

        for char in str {
            automatic.getNewChar(char)
        }

        return automatic.sign * automatic.result

    }
}
```