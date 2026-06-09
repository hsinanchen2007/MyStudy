1. 获取每个数字出现的次数、出现的最小次数
2. 最小次数小于等于1时不符合要求直接返回
3. 遍历从2到最小次数获得最大公约数
4. 如果有最大公约数就返回true 否则就是false
### 代码

```swift
class Solution {
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        var sameMap: [Int: Int] = [:]
        var min = 0;
        for current in deck {
            if let count = sameMap[current] {
                sameMap[current] = count + 1;
            } else {
                sameMap[current] = 1
            }
            if min < sameMap[current] ?? 0 {
                min = sameMap[current] ?? 0
            }
        }
        if min <= 1 {
            return false;
        }
        for index in 2...min {
            if sameMap.values.allSatisfy({$0%index == 0}) {
                return true
            }
        }
        return false
    }
}
```