```
class Solution {
     func reverseBetween(_ head: ListNode?, _ m: Int, _ n: Int) -> ListNode? {
        guard head != nil else {
            return nil
        }
        let dummyNode = ListNode(0)
        dummyNode.next = head
        var p1: ListNode? = dummyNode
        var i = 1
        //找到第一段的为节点p1
        while p1?.next != nil && i < m {
            p1 = p1?.next
            i += 1
        }
        var p2 = p1?.next //p1是前一段的尾结点，p1值保留，新建立一个p2进行遍历。
        var pre: ListNode?
        i = m
        while p2 != nil && i <= n {
            let curNext = p2?.next
            p2?.next = pre
            pre = p2
            p2 = curNext
            i += 1
        }
        p1?.next?.next = p2 //这个地方p1.next.next不就是中间段翻转后的尾巴节点，在这个地方卡了会儿。
        p1?.next = pre
        return dummyNode.next
    }
}
```