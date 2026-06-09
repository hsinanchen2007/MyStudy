### 解题思路
此处撰写解题思路

### 代码

```scala
/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
    def getDecimalValue(head: ListNode): Int = {
    var h = head
    var sum = 0
    while (h != null) {
      sum = sum * 2 + h.x
      h = h.next
    }
    sum   
    }
}
```