### 解题思路
1. 使用三个节点，pre保存反转结果，cur代表当前遍历到的节点，next保存未反转部分。
2. 代码中有详细注释和示例。

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
        ListNode pre = null;
        ListNode cur = head;
        while(cur != null){//1->2->3->null
            ListNode next = cur.next; //保存未反转部分 2->3->null 3->null null
            cur.next = pre; //当前节点的next指向前一个节点(反转部分) 1->null 2->1->null 3->2->1->null
            pre = cur; //保存反转结果 1->null 2->1->null 3->2->1->null
            cur = next;// 2->3->null 3->null null
        }
        return pre;
    }
}
```