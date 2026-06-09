### 解题思路
字典树的方法，倒是没有用，为了启发思路，手打一边领会了一下
这道题目，为了找出最短字符，为了不使用排序，以长度为key的字典，value为长度为key的集合，
为了缩短时间，采用一次遍历sentence，手动判断的方式，而题解的方式，会多次遍历sentence，其他就是暴力破解

### 代码

```swift
    func replaceWords(_ dict: [String], _ sentence: String) -> String {
        var minLength = Int.max
        var lengthDict = [Int: Set<String>]()
        for word in dict {
            if word.count < minLength {
                minLength = word.count
            }
            lengthDict[word.count, default: Set<String>()].insert(word)
        }
        var curStr = ""
        var curFinish = false
        let kong = Character(" ")
        var res = ""
        for c in sentence {
            if c == kong {
                if !curFinish {
                    res.append(curStr)
                }
                curStr.removeAll()
                curFinish = false
                res.append(kong)
            } else {
                if curFinish {
                    continue
                }
                curStr.append(c)
                
                if let curDict = lengthDict[curStr.count], curDict.contains(curStr) {
                    res.append(curStr)
                    curFinish = true
                }
            }
        }
        if !curFinish {
            res.append(curStr)
        }
        return res
    }
```