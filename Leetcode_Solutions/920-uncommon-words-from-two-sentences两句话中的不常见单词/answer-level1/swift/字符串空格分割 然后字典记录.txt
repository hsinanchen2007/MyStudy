Swift代码
```
func uncommonFromSentences(_ A: String, _ B: String) -> [String] {
        let arrA = A.split(separator: " ")
        let arrB = B.split(separator: " ")
        var map = [Substring:Int]()
        for subStr in arrA {
            if let count = map[subStr] {
                map[subStr] = count + 1
            } else {
                map[subStr] = 1
            }
        }
        for subStr in arrB {
            if let count = map[subStr] {
                map[subStr] = count + 1
            } else {
                map[subStr] = 1
            }
        }
        var res = [String]()
        for (key, val) in map {
            if val == 1 {
                res.append(String(key))
            }
        }
        return res
    }
```