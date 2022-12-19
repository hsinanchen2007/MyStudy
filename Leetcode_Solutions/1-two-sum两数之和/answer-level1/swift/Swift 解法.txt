有时候感觉题目有歧义, "你不能重复利用这个数组中同样的元素。", 结果测试用例也有 [3,3] 这种相同元素的情况...

暴力双指针, 时间复杂度 O(n^2), 空间复杂度 O(1)
```
func sulotion_1(_ nums: [Int], _ target: Int) -> [Int] {
    var index = 1
    for i in 0..<nums.count-1 {
        for j in index..<nums.count {
            if nums[i]+nums[j] == target {
                return [i, j]
            }
        }
        index = index + 1
    }
    
    return []
}
```

额外使用字典, 时间复杂度 O(2n), 空间复杂度 O(n)
```
func sulotion_2(_ nums: [Int], _ target: Int) -> [Int] {
    var dic = [Int : Int]()
    for i in 0..<nums.count {
        dic[nums[i]] = i
    }
    for i in 0..<nums.count {
        let found = target - nums[i]
        if let j = dic[found], i != j {
            return [i, j]
        }
    }
    return []
}
```
