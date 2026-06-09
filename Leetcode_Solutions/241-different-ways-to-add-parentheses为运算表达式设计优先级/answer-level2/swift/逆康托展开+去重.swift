### 解题思路

拆分数字与运算符，对运算符先后顺序用逆康托展开进行全排列
得出所有对表达式与结果，去重排序后输出
需要处理无运算符情况，以及提交的Swift String不支持%@

### 代码

```swift
class Solution {

    let facAry = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

    func diffWaysToCompute(_ input: String) -> [Int] {
        let mark = 100000
        var opIdxDic = [Int: String]()
        
        var ipt = ""
        for char in input {
            if char == "+" || char == "-" || char == "*" {
                let idx = mark + opIdxDic.count
                let ope = String(char)
                ipt += String(format: ",%d,", idx)
                opIdxDic[idx] = ope
                continue
            }
            ipt += String(char)
        }
        let numAry = ipt.components(separatedBy: ",").map { Int($0) ?? 0 }
        
        var optDic = [String: Int]()
        let len = facAry[opIdxDic.count]
        for i in 0..<len {
            var subNumAry = numAry
            var subStrAry = subNumAry.map { String($0) }
            
            for opIdx in deCantor(ct: i, n: opIdxDic.count) {
                for j in 0..<subNumAry.count {
                    let op = subNumAry[j]
                    if op != mark + opIdx {
                        continue
                    }
                    
                    let numL = subNumAry[j - 1], numR = subNumAry[j + 1]
                    let strL = subStrAry[j - 1], strR = subStrAry[j + 1]
                    var num = 0
                    var str = ""
                    switch opIdxDic[subNumAry[j]] {
                    case "+":
                        num = numL + numR
                        str = "(" + strL + "+" + strR + ")"
                    case "-":
                        num = numL - numR
                        str = "(" + strL + "-" + strR + ")"
                    case "*":
                        num = numL * numR
                        str = "(" + strL + "*" + strR + ")"
                    default: break
                    }
                    for _ in 0..<2 {
                        subNumAry.remove(at: j - 1)
                        subStrAry.remove(at: j - 1)
                    }
                    subNumAry[j - 1] = num
                    subStrAry[j - 1] = str
                    break
                }
            }
            
            optDic[subStrAry[0]] = subNumAry[0]
        }
        
        var optAry = [Int]()
        for kv in optDic {
            optAry.append(kv.value)
        }
        
        return optAry.sorted()
    }
    
    func deCantor(ct: Int, n: Int) -> [Int] {
        if n <= 0 {
            return []
        }
        
        var optAry = Array.init(repeating: 0, count: n)
        var numAry = Array.init(repeating: 0, count: n)
        for i in 0..<n {
            numAry[i] = i
        }
        
        var x = ct
        for i in 1...n {
            let r = x % facAry[n - i]
            let t = x / facAry[n - i]
            x = r
            optAry[i - 1] = numAry[t]
            numAry.remove(at: t)
        }
        
        return optAry
    }
}
```