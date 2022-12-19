Swift 一遍Hash

```
  static func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var hashTable: Dictionary<Int, Int> = [:]
        for (index, value) in nums.enumerated() {
            let targetNum = target - value;
            if hashTable.keys.contains(targetNum) {
                return [hashTable[targetNum]!, index]
            }
            hashTable.updateValue(index, forKey:value)
        }
        return []
    }
```
