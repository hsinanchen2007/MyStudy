```
/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
    def middleNode(head: ListNode): ListNode = {
        val nodes: Array[ListNode] = new Array[ListNode](100 + 1)
        var length = 0;
        var temp = head
        //遍历链表，放入数组
        while (temp != null) {
            length += 1;
            nodes(length) = temp;
            //链接下一个节点
            temp = temp.next
        }
        return nodes(length / 2 + 1);
    }
}
```
