用一个栈把需要记录反转的数字记录，然后再把栈里面的数字重新赋值到链表中。
```
import java.util.Stack
object Solution {
    def reverseBetween(head: ListNode, m: Int, n: Int): ListNode = {
        var newHead = head
        var index = 1
        val stack: Stack[Int] = new Stack[Int]()
        while(newHead != null){
          if(index >= m && index <= n){
            stack.push(newHead.x)
          }
          newHead = newHead.next
          index += 1
        }

        newHead = head
        index = 1
        while(newHead != null){
          if(index >= m && index <= n){
            newHead.x = stack.pop()
          }
          newHead = newHead.next
          index += 1
        }
        head
    }
}
```

