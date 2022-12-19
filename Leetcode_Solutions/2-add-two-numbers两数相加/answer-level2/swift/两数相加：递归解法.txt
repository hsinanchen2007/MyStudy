整体思路就是两个 ListNode 从第一个节点开始相加，记录是否进位，然后做好判断直接完成

```
func getResult(_ l1: ListNode?, _ l2: ListNode?, _ carry: Int?) -> ListNode? {
        guard (l1 != nil || l2 != nil) || carry != nil else {
            return nil
        }
        let sum = (l1?.val ?? 0) + (l2?.val ?? 0) + (carry ?? 0)
        let i = sum % 10
        let j = sum / 10
        let c: Int? = j > 0 ? j : nil
        
        let l3 = ListNode(i)
        l3.next = getResult(l1?.next, l2?.next, c)
        return l3
}
```
