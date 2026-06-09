### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.4 MB, 在所有 Java 提交中击败了5.07%的用户

1.造两个指针，1个指向当前节点cur，1个指向它的下一个节点next
2.先处理第一个节点，并给cur和next赋初始值,另cur.next=null以符合题意
3.进入循环：只要next!=null则做指针反转，同时多出一个tmp指针来保留next.next
4.最终cur即原列表尾节点，及新列表头节点

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
        if (head==null) return null;
        
        ListNode cur = head;
        ListNode next = cur.next;
        cur.next = null;
        while (next!=null) {
            ListNode tmp = next.next;
            next.next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }
}
```