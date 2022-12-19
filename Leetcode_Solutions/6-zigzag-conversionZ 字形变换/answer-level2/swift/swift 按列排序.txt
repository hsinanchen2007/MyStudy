```
class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
        guard numRows > 1 else {
            return s
        }
        var arr = Array.init(repeating: [Character](), count: numRows)
        var strArr = Array(s)
        var column = 0
        while strArr.first != nil {
            let current = column % (numRows - 1)
            if current == 0 {
                for i in 0..<numRows {
                    if let first = strArr.first {
                        arr[i].append(first)
                        strArr.removeFirst()
                    } else {
                        arr[i].append(" ")
                    }
                }
            } else {
                for i in 0..<numRows {
                    if i == numRows - current - 1 {
                        arr[i].append(strArr.removeFirst())
                    } else {
                        arr[i].append(" ")
                    }
                }
            }
            column += 1
        }
        var str = ""
        for a in arr {
            for c in a {
                guard c != " " else {
                    continue
                }
                str += "\(c)"
            }
        }
        return str
    }
}
```