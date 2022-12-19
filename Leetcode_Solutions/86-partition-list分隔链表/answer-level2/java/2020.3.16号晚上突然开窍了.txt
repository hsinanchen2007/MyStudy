### 解题思路
先创建两个空链表，两个空指针分别指向这两个空链表，接下来遍历原先的链表，遍历过程中当val＜x时，将这个节点取出来给其中一个链表，否则给另一个，遍历完成后，将val>x的链表最后一个节点为null，再返回第一个链表，就成功了。

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
    public ListNode partition(ListNode head, int x) {
        ListNode lastnewhead = new ListNode(0);
        ListNode last = lastnewhead;
        ListNode currnewhead = new ListNode(0);
        ListNode curr = currnewhead;
        while(head != null){
            if(head.val < x){
                last.next = head;
                last = last.next;
            }else{
                curr.next = head;
                curr = curr.next;
            }
            head = head.next;
        }
        curr.next = null;
        last.next = currnewhead.next;
        return lastnewhead.next;
    }
}
```