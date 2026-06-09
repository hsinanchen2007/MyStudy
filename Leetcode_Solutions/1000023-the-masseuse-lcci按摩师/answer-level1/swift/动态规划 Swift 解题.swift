### 解题思路
此处撰写解题思路
- 设置两个值，
    - 前 i 个里，最后一个不接的最大值 ret_0
    - 前 i 个里，最后一个接的最大值 ret_1
    - 初始值（i = 1）时: ret_0 = 0, ret_1 = nums[0]
- 遍历数组，依次计算得出前 1，2，3直到 nums.count 为止的最大值
    - 增加两个值来表示当前 i 个里，最后一个不接和接的值，和上一个作比较，来获取最大值
    - 最后一个不接的值：前 i-1 个里最后一个接的最大值, cur_0 = ret_1
        - 比如：i = 2 时: cur_0 = 前1个里面第1个接的最大值
    - 最后一个接的值：前 i-1 个里最后一个不接的值 + 当前值
        - 比如：i = 2 时：cur_1 = ret_0 + nums[1]
    - 获取最新的 ret_0 和 ret_1
        - ret_0 = max(ret_0, cur_0)
        - ret_1 = max(ret_1, cur_1)
- 最后结果为，数组最后一个接和最后一个不接的最大值，即 max(ret_0, ret_1)
### 代码

```swift
class Solution {
    func massage(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        //ret_0 表示前 i 个里的最大值，第 i 个不接
        var ret_0 = 0
        //ret_1 表示前 i 个里的最大值，第 i 个接
        var ret_1 = nums[0]
        for i in 1..<nums.count {
            
            //当前，前 i 个里，第 i 个不接，即为前 i-1 个第 i 个接的最大值
            var cur_0 = ret_1
            //当前，前 i 个里，第 i 个接，即为前 i-1 个里面，第 i 个不接的最大值 + 当前 nums[i]
            var cur_1 = ret_0 + nums[i]
            
            //将当前 i 的最大值和之前 i-1 的值做比较，取最大值。并赋值给前 i 个的最大值。
            ret_0 = (ret_0 > cur_0 ? ret_0 : cur_0)
            ret_1 = (ret_1 > cur_1 ? ret_1 : cur_1)
        }
        return (ret_0 > ret_1 ? ret_0 : ret_1)
    }
}
```