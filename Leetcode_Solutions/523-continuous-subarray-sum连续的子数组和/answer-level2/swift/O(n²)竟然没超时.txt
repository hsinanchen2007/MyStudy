看到题目的数据量大小就觉得O(n²)应该不会超时
sum[i]记录从0到i的数组的和
所以要求i~j的和 就是sum[j] - sum[i - 1] （i > 0）
于是长度从2开始一直到数组长度
数组从下标0开始遍历
```
class Solution {
    func checkSubarraySum(_ nums: [Int], _ k: Int) -> Bool {
        let len = nums.count
        if len == 0 {
            return k == 0
        }
        var sums = Array(repeating: 0, count: len)
        sums[0] = nums[0]
        for i in 1 ..< len {
            sums[i] = sums[i - 1] + nums[i]
        }
        for l in 2 ..< len + 1 {
            for i in 0 ..< len - l + 1 {
                let left = i
                let right = i + l - 1 // i + k - 1 < len
                var sum = 0
                if left > 0 {
                    sum = sums[right] - sums[left - 1]
                } else {
                    sum = sums[right]
                }
                if sum == 0 {
                    return true
                }
                if k == 0 {
                    if k == sum {
                        return true
                    }
                } else {
                    if sum % k == 0 {
                        return true
                    }
                }
            }
        }
        return false
    }
}
```