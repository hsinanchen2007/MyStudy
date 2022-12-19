### 解题思路
此处撰写解题思路
1、删除倒数第n个节点，就是删除链表上的某一节点的意思。
2、解题思路：
   先遍历整个链表，找到链表的长度（使用while循环）
   获得链表长度length,删除节点为 length-n+1,既循环到被删节点的前一个节点length-n
   最后只需要被删节点的前一节点的next指向被删节点的next
3、 但是要注意，刚好删除的是头结点。因此，可以使用一个哑节点指向头节点
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //存一个哑结点
        ListNode dummyNode = new ListNode(0);
        dummyNode.next = head;
        ListNode first = head.next;
        int length = 0;
        while(first != null){
            length++;
            first = first.next;
        }
        first = dummyNode;
        for(int i =0;i<length-n+1;i++){
            first=first.next;
        }
        first.next = first.next.next;
        return dummyNode.next;
    }
}
```