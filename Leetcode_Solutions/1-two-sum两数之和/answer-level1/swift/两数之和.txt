受排名第一的题解（力扣 (LeetCode)：官方题解）而作，重复理解大佬们的想法，然后翻译成swift，记录以飨读者。
方法一：穷举
```
    func twoSumForcesearch(_ nums: [Int], _ target: Int) -> [Int] {
        for i in 0..<nums.count-1 {
            for j in i+1..<nums.count {
                if i == j {
                    continue
                }
                if nums[i] == target - nums[j] {
                    return [i, j]
                }
            }
        }
        return [0]
    }
```

方法二：利用字典特性，通过key来判断value是否存在，key为数组各元素的值，value为元素对应下标
```
    func twoSumHashtable(_ nums: [Int], _ target: Int) -> [Int] {
        var hashmap: [Int: Int] = [Int: Int]()
        for i in 0..<nums.count {
            hashmap[nums[i]] = i
        }
        
        for i in 0..<nums.count {
            let dif = target - nums[i]
            
            if hashmap[dif] != nil && hashmap[dif] != i {
                return [i, hashmap[dif]!]
            }
        }
        
        return [0]
    }
```


方法三：一次遍历。这个 一次遍历 很妙啊，两数之和，第一个一定会错过，但第二个不会。本人适当做了优化，hashmap[dif]直接判断是否有值，由于是线性操作，时间复杂度O(1)，原作者的containkey方法内部实现应该是一个循环O(n)。
```
    func twoSumHashtable2(_ nums: [Int], _ target: Int) -> [Int] {
        var hashmap: [Int: Int] = [Int: Int]()
        let size: Int = nums.count
        
        for i in 0..<size {
            let dif = target - nums[i]
            if hashmap[dif] != nil && hashmap[dif] != i {
                return i > hashmap[dif]! ? [hashmap[dif]!, i] : [i, hashmap[dif]!]
            } else {
                hashmap[nums[i]] = i
            }
        }
        
        return [0]
    }
```
