用三个指针遍历，完成反转即可。pre指针因为要作为尾节点，所以初始化时需要指向null。
每次修改指针前，用一个next存储下一个节点的地址，这样交换完后才能找到。

```
object Solution {
    def reverseList(head: ListNode): ListNode = {
        if(head == null || head.next == null) return head
        var pre:ListNode = null
        var cur = head
        while(cur!=null){
            val next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        }
        pre
    }
}
```
至于递归，思路一样的，讲解起来会没那么只管。
每一层递归其实都是把当前节点指向的后面全部reverse。
对于最底层的一个点，我们先让其临时指向null，当我们递归到上一层时，就能够很轻易的找到他对应的next应该指向的节点。
具体到某一个点，其实他后面已经完成了reverse，且head.next被两个节点所指向：head，head.next.next。
所以我们把head.next的next指向，以及head.next的指向修正即可。
```
object Solution {
    def reverseList(head: ListNode): ListNode = {
        if(head == null || head.next == null) return head
        val p = reverseList(head.next)
        head.next.next = head
        head.next = null
        p
    }
}
```