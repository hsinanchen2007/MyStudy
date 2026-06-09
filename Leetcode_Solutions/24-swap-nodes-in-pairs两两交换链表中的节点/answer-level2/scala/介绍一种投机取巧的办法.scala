只交换值即可，主要是交换next指针太麻烦。
```
object Solution {
    def swapPairs(head: ListNode): ListNode = {
        var newHead = head
        while(newHead != null && newHead.next != null){
            val temp = newHead.x
            newHead.x = newHead.next.x
            newHead.next.x = temp
            newHead = newHead.next.next
        }
        head
    }
}
```
