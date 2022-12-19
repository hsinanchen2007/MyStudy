
### 暴力解法

执行用时 : 196 ms , 在所有 swift 提交中击败了 90% 的用户
内存消耗 : 24.3 MB , 在所有 swift 提交中击败了 7.14% 的用户

```swift
class Solution {
    
    func rangeMaxElement(_ nums: [Int], _ l: Int, _ r: Int) -> (idx: Int, val: Int){
        
        var maxValue = nums[l]
        var idx = l
        for i in l...r {
            if nums[i] > maxValue {
                maxValue = nums[i]
                idx = i
            }
        }
        return (idx, maxValue)
    }
    
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {

        // 暴力解法
        if k <= 0 {
            return []
        }else if k == 1 {
            return nums;
        }
        
        var maxArr = [Int]()
        var idx = 0
        //第一个k里面的最大值
        let frb = rangeMaxElement(nums, 0, min(k-1, nums.count-1))
        maxArr.append(frb.val)
        idx = frb.idx
        if k == nums.count {
            return maxArr
        }
        
        //剩余的max
        for i in k..<nums.count {
            if idx < (i-k+1) {
                // 上一次的 max 不在窗口内，重新做一个窗口最大值的检索
                let crb = rangeMaxElement(nums, i-k+1, i)
                maxArr.append(crb.val)
                idx = crb.idx
            }else if maxArr.last! > nums[i] {
                maxArr.append(maxArr.last!)
            }else{
                maxArr.append(nums[i])
                idx = i
            }
        }
        
        return maxArr
    }
}
```





### 双端队列

执行用时 : 228 ms , 在所有 swift 提交中击败了 56.67% 的用户
内存消耗 : 24.3 MB , 在所有 swift 提交中击败了 7.14% 的用户

```swift
class Solution {
    
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        

        // 双端队列 O(n)
        if k <= 0 {
            return []
        }else if k == 1 {
            return nums;
        }
        var maxArr = [Int]()
        var doubleQueue = [Int]() //模拟一个双端队列的索引
        var maxIdx = 0
        for idx in 0..<nums.count {
            //超出窗口则移除
            if idx - maxIdx + 1 > k {
                doubleQueue.removeFirst()
            }
            // 遍历移除当前队列中比自己小的所有元素 O(1) ~ O(k-x)
            while !doubleQueue.isEmpty && nums[doubleQueue.last!] < nums[idx] {
                doubleQueue.removeLast()
            }
            doubleQueue.append(idx)
            maxIdx = doubleQueue.first!
            if idx+1 >= k {
                maxArr.append(nums[maxIdx])
            }
        }
        
        return maxArr
    }
}
```




### 动态规划

执行用时 : 184 ms , 在所有 swift 提交中击败了 96.67% 的用户
内存消耗 : 24.8 MB , 在所有 swift 提交中击败了 7.14% 的用户

```swift
class Solution {
    
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        
        // 动态规划 O(n)
        let n = nums.count
        if n * k <= 0 {
            return []
        }else if k == 1 {
            return nums;
        }
        
        var maxArr = [Int]()
        var left = [Int]()
        var right = Array(repeating: 0, count: n)

        for i in 0..<n {
            
            if i % k == 0 {
                left.append(nums[i])
            }else{
                left.append(max(nums[i], left.last!))
            }
            
            let j = n - i - 1
            if (j+1) % k == 0 || i == 0 {
                right[j] = nums[j]
            }else{
                right[j] = max(right[j+1], nums[j])
            }
            
        }
        
        for i in k-1..<n {
            maxArr.append(max(left[i], right[i-k+1]))
        }
        
        return maxArr
    }
}
```