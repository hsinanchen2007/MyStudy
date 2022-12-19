### 解题思路
删除单链表的元素，要找到被删除元素的前一个节点。
直接创建一个虚拟头节点，让虚拟头节点的下一个元素指向头节点，然后我们每次比较当前节点的下一个节点的值同`val`是否相同就可以，如果相同，就删除，继续比较下一个节点。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummyHead = new ListNode(-1);// 创建虚拟头节点
        dummyHead.next = head;

        ListNode prev = dummyHead;
        while(prev.next != null){// 每次比较当前节点的下一个节点
            if(prev.next.val == val){
                prev.next = prev.next.next;
            }else{
                prev = prev.next;
            }
        }
        return dummyHead.next;
    }
}
```