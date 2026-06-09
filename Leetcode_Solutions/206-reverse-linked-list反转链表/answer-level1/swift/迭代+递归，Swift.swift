# 一、迭代法
```
class Solution {
    /* 迭代法
        依次遍历每个结点，将该结点 next 指向上一个结点
        用一个临时变量保存上一个结点
    
    时间复杂度：O(n)，因为涉及到遍历
    空间复杂度：O(1)，没有额外开销
    */
    func reverseList(_ head: ListNode?) -> ListNode? {
        // 保存上一个结点
        var pre: ListNode? 
        // 当前遍历的结点
        var head = head
        
        while head != nil {
            // 当前结点的下一个结点
            let next = head!.next
            // 将当前结点 next 指向上一个结点
            head!.next = pre
            // 向后移动上一个结点和当前结点
            pre = head
            head = next
        }
        
        return pre
    }
}
```
# 二、递归法
```
class Solution {
    /* 递归法
        反转 n1->n2->...->nm，相当于反转 n1->(nil<-n2<-...<-nm)
        所以最小单位为只有两个结点的链表的反转
        而反转 nk->n(k+1) 即为 nk.next.next = nk
        子链表反转完毕后将头结点指向 null
        
    时间复杂度：O(n)，因为涉及到遍历
    空间复杂度：O(n)，因为递归的深度会有额外开销
    */
    
    func reverseList(_ head: ListNode?) -> ListNode? {
        // 终止条件，只剩下一个结点
        guard let h = head, let next = h.next else { return head }
        
        // 先反转当前结点之后的所有结点
        let node = reverseList(next)
        // 反转当前结点和下一个结点
        next.next = head
        // 将当前结点指向 null
        h.next = nil
        
        return node
    }
}
```