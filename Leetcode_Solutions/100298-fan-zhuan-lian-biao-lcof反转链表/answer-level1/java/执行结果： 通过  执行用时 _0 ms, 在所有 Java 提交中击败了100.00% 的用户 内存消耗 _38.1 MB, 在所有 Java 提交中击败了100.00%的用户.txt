### 解题思路
此处撰写解题思路
1.创建新的头结点，初始值随便设
2.遍历原先链表，每摘下一个节点就插入在新头结点后方
3.返回新头结点的下一个节点即可
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
    public ListNode reverseList(ListNode head) {
        ListNode reverseHead = new ListNode(0); //头结点
        ListNode cur = head; //旧链表的第一个节点，当前指针
        ListNode next = null; // 旧链表的下一个节点，下一个指针
        while(cur != null){
            next = cur.next; //下一个指针后移
            cur.next = reverseHead.next; // 摘下的节点指向新链表的第一个节点
            reverseHead.next = cur; //让新头结点指向摘下来的节点 这两步即完成插入
            cur = next; //当前指针后移
        }
        return reverseHead.next; //返回新链表的第一个节点
    }
}
```