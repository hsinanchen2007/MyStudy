解法一
```
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init (_ val: Int) {
        self.val = val
        self.next = nil
    }
}

func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) ->ListNode? {
    var l1 = l1
    var l2 = l2
    let phead = ListNode(-1)
    var preN = phead
    while l1 != nil && l2 != nil {
        if l1!.val <= l2!.val {
            preN.next = l1
            l1 = l1?.next
        } else {
            preN.next = l2
            l2 = l2?.next
        }
        preN = preN.next!
    }
    preN.next = l1 == nil ? l2: l1
    return phead.next
}

```
解法二: 递归
```
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init (_ val: Int) {
        self.val = val
        self.next = nil
    }
}
func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    } else if l1!.val <= l2!.val {
        l1?.next = mergeTwoLists(l1?.next, l2)
        return l1
    } else {
        l2?.next = mergeTwoLists(l1, l2?.next)
        return l2
    }
    }
```
