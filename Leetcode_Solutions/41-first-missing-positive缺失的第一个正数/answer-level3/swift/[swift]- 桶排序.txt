
[桶排序Wiki](https://zh.wikipedia.org/wiki/%E6%A1%B6%E6%8E%92%E5%BA%8F)

对于这道题来讲 
每个桶只放合适自己的元素
(1 放到第0个桶中  3 放到第2个桶中)
(对于 num[i] > 0 且 <= nums.count 的元素来说 nums[i]放到第num[i]-1的桶中)
因此对于 不符合 
`nums[i] > 0 && nums[i] <= nums.count && nums[nums[i] - 1] != nums[i]`
的元素 进行交换处理
这里交换注意顺序 需要先记录 nums[nums[i] - 1]
否则nums[i]的数据不正确

最后找出来 位置不正常的第一个元素 索引+1 就是目标值

```
func firstMissingPositive(_ nums: [Int]) -> Int {
        var newNums = nums
        if newNums.count == 0 {return 1}
        for i in 0..<newNums.count{
            while newNums[i] > 0 && newNums[i] <= newNums.count && newNums[newNums[i] - 1] != newNums[i]{
                let tmp = newNums[newNums[i] - 1]
                newNums[newNums[i] - 1] = newNums[i]
                newNums[i] = tmp
            }
        }
        for i in 0..<newNums.count{
            if newNums[i] != i + 1 {
                return i + 1
            }
        }
        return newNums.count + 1
    }
```
