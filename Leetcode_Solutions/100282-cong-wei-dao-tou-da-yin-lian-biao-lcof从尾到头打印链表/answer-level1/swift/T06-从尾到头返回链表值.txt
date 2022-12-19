### 解题思路
将链表遍历加入数组，然后将数组反置输出即可。

### 代码

```swift
class Solution {
    func reversePrint(_ head: ListNode?) -> [Int] {
        // 初始化数组
        var nums: [Int] = []
        
        // 遍历链表
        var temp = head
        while temp != nil {
            nums.append(temp!.val)
            temp = temp?.next
        }
        
        // 不能直接返回nums.reversed(),因为该函数不能直接返回[Int]。
        nums = nums.reversed()
        return nums
    }
}

```