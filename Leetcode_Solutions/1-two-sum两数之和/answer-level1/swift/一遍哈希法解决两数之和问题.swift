
一遍哈希法的原理：通过以空间换取时间的方式，优化执行时间。

> 在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

```swift
func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    // 首先执行安全检查，判断传入数组是否为空
    if nums.isEmpty { return [] }
    // 创建一个空的 Dictionary 字典，用于存储已经被索引过的数值
    var hashTable = [Int: Int]()
    for (index, value) in nums.enumerated() {
        // 期望目标值 = 总和 - 当前值
        let targetNum = target - value
        // 如果字典中存在「期望目标值」，则返回「期望目标值」的索引和「当前值」的索引
        if hashTable.keys.contains(targetNum) {
            return [hashTable[targetNum]!, index]
        }
        // 如果不存在「期望目标值」，则把「当前值」和「当前值」在数组中的索引保存到字典中
        // 优点：只要遍历一遍，数组中被遍历过的值都会被临时存储
        // 注意：Dictionary 中存的 key 为数值，value 为数组索引
        hashTable.updateValue(index, forKey: value)
    }
    // 如果传入的数组中不存在解，则返回空数组
    return []
}
```