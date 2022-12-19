```scala
object Solution {
  def deleteDuplicates(head: ListNode): ListNode = head match {
    case null => head
    case _ =>
      var node = head
      if (node.next != null && node.x == node.next.x) {
        while (node.next != null && node.x == node.next.x) node = node.next
        return deleteDuplicates(node.next)
      }
      node.next = deleteDuplicates(node.next)
      node
  }
}
```
