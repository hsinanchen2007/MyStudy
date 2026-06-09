1 reverse 函数特效
  $reverse(a_0,...,a_n) = reverse(a_1, ..., a_n) + a_0$
```scala
object Solution {
    type T = ListNode
    def f(head:T, acc:T): T = head match {
        case null => acc
        case _ =>
            val p = head.next
            head.next = acc
            f(p, head)
    }
    def reverseList(head: T): T = f(head, null)
}
```
