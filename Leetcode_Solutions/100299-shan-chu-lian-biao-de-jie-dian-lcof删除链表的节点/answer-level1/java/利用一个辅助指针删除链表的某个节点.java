### 解题思路
1.需要一个辅助指针帮助遍历以及实现删除节点；
2.用while循环体，条件为链表不为空；
3.首先判断第一个节点是否为被删除的节点，是则删除并返回head=head.next;
4.遍历每一个非空节点且满足val与输入相等；
5.将上一个节点的next和下一个节点的next连接，删除被目标节点（被“删除”的节点交给GC处理）
6.返回头节点head；

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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode temp =head;
       while(head!=null){
           if(head.val == val) return head = head.next;
           if(temp.next!=null && temp.next.val==val){
               temp.next = temp.next.next;
               return head;
           }
           temp = temp.next;
       }
       return head;
    }
}
```