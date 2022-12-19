解题思路分为3个步骤：
1. 通过快慢走法找到m-1, m, n, n+1四个结点，将n的next置为nil
2. 将m到n的子链表进行反转
3. 最后拼接各个结点： ... -> m-1 -> n -> ... -> m -> n+1 -> ..

代码如下：

```
func reverseList(_ head: ListNode?) -> ListNode? {
    var reverseHead: ListNode?, current = head, previous: ListNode?

    while current != nil {
        let next = current!.next
        if next == nil { reverseHead = current }

        current!.next = previous
        previous = current
        current = next
    }

    return reverseHead
}

func reverseBetween(_ head: ListNode?, _ m: Int, _ n: Int) -> ListNode? {
    guard head != nil else { return nil }
    
    let dummy = ListNode(-1)
    dummy.next = head
    
    var front: ListNode? = dummy, behind: ListNode? = dummy
    var behindPre: ListNode? = nil
    
    for i in 0..<n {
        if i < n - m {
            front = front?.next
            continue
        }
        
        behindPre = behind
        behind = behind?.next
        front = front?.next
    }
    
    let frontNext = front?.next
    front?.next = nil

    _ = reverseList(behind)

    behindPre?.next = front
    behind?.next = frontNext

    return dummy.next
}

```
