```
class Solution {
    func deleteNode(_ head: ListNode?, _ val: Int) -> ListNode? {
        guard head != nil else {
            return nil
        }
        var pre: ListNode?
        var cur = head
        if cur!.val == val {
            return cur!.next
        }
        while cur != nil {
            if cur!.val == val {
                pre?.next = cur!.next
                break
            }
            pre = cur
            cur = cur!.next!
        }
        return head
    }
}
```
//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass