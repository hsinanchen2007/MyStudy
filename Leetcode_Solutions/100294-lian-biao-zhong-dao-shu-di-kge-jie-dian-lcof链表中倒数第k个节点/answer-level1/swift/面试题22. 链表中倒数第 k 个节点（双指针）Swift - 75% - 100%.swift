```
class Solution {
    func getKthFromEnd(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard head != nil else {
            return nil
        }
        var fast = head
        var slow = head
        var index = 0
        while fast != nil {
            if index < k - 1 {
                fast = fast?.next
                index += 1
                continue
            } else if index == k - 1 {
                fast = fast?.next
                slow = head
                index += 1
                continue
            }
            fast = fast?.next
            slow = slow?.next
            index += 1
        }
        return slow
    }
}
```
//提升数据结构和算法，刷题日记，每日积累一点。github仓库包括”跟随极客时间课程例题“、”leetcode高频题目“、”剑指offer的题目“，语言使用Swift和极少部分的Java，欢迎访问一起进步：https://github.com/iAronTalk/Algorithm-DataStructures-Pass