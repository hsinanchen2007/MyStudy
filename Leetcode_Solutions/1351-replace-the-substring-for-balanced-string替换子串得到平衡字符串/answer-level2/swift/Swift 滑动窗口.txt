```swift
func balancedString(_ s: String) -> Int {
    let sArray = s.map { $0 }
    var dic = [Character: Int]()
    let count = s.count
    let single = count / 4
    for c in s {
        dic[c, default: 0] += 1
    }
    var curDic = [Character: Int]()
    var needDic = [Character: Int]()
    var need = 0
    for (key, value) in dic {
        if value > single {
            needDic[key] = value - single
        }
    }
    
    func check() -> Bool {
        let keys = Array(needDic.keys)
        for key in keys {
            if curDic[key, default: 0] < needDic[key]! {
                return false
            }
        }
        return true
    }
    
    if needDic.isEmpty {
        return 0
    }
    var left = 0
    var right = 0
    var ans = Int.max
    while right < count && left <= right {
        curDic[sArray[right], default: 0] += 1
        while check() {
            ans = min(ans, right - left + 1)
            curDic[sArray[left], default: 0] -= 1
            left += 1
        }
        right += 1
    }
    
    return ans
}

```
