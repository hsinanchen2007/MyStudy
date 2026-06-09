### 解题思路

开始没注意题目条件，有序，且不考虑超出新长度后的元素，当时用的倒序删除。
一旦想到（看评论的）用指针，赋值就OK了，多个测试用例用时是不一样的。。。


### 代码

```swift
class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        let count = nums.count
        if count <= 1 {
            return count
        }
        var k = 0
        for i in 1 ..< count {
           if nums[i] != nums[k] {
               k += 1
               nums[k] = nums[i]
           }
        }
        return  k+1
    }
}
```