使用 Swift 字典替代 Set，num 为 key，index 为 value。

```
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic = [Int: Int]()
        for (index, num) in nums.enumerated() {
            let complement = target - num
            if let i = dic[complement] {
                return [i, index]
            }
            dic[num] = index
        }
        return []
    }
```
