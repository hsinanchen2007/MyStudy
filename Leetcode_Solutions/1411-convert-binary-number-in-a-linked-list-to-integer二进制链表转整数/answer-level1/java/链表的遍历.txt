### 解题思路
这道题的本质核心思想: 
1. 链表的遍历；
2. 进制的换算

### 代码

```kotlin
/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun getDecimalValue(head: ListNode?): Int {
       var head: ListNode? = head ?: return 0
    var string =  ""
    while(head!=null){
        string += head.`val`.toString()
        head = head.next
    }
    return string.toInt(2)
    }
}
```