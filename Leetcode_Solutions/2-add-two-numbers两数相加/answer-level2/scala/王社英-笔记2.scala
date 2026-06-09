1,这个就是小学计算一位一位的加,除了加数和被加数,还有进位,思想很简单
```
object Solution {
  def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
    var flag = 0
    var reminder = 0
    val sum = new ListNode()
    var next = sum
    var left = l1
    var right = l2
    while (left != null || right != null) {
      var leftValue = 0
      if (left != null) {
        leftValue = left.x
        left = left.next
      }
      var rightValue = 0
      if (right != null) {
        rightValue = right.x
        right = right.next
      }
      val s = leftValue + rightValue + flag
      flag = s / 10
      reminder = s % 10
      println(reminder)
      next.next = new ListNode(reminder)
      next = next.next
    }
    if (flag == 1) {
      println(flag)
      next.next = new ListNode(flag)
      next = next.next
    }
    return sum.next
  }
}

```
