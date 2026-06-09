### 解题思路
首先找到 m 节点的前一个节点，看作头插法的哑巴节点，然后一直头插，n-m 次即可

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null || m == n) return head;

        // 创建哑巴节点
        ListNode help = new ListNode(-1); 
        help.next = head;
        ListNode mNode = help;
        int step = m;

        //找到第一个需要反转节点的前一个节点
        while(step > 1 && mNode != null){
            mNode = mNode.next;
            step--;
        }
        ListNode p = mNode.next;
        ListNode q = mNode.next.next;
        
        //头插 插 n-m 次 就达成反转
        while(n-m>0){
            p.next = p.next.next;
            q.next = mNode.next;
            mNode.next = q;
            q = p.next;
            n--;
        }

        return help.next;
    }
}
```