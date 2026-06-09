### 解题思路
此处撰写解题思路
利用双栈和头插法快速得出解

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        ListNode reN = new ListNode(-1);
        ListNode head = reN.next;

        while(l1 != null){
            s1.push(l1.val);
            l1 = l1.next;
        }
        while(l2 != null){
            s2.push(l2.val);
            l2 = l2.next;
        }
        int jinwei = 0;
        while(!s1.isEmpty() || !s2.isEmpty() || jinwei == 1){
            int v1 = s1.isEmpty()?0:s1.pop();
            int v2 = s2.isEmpty()?0:s2.pop();
            int sum = v1+v2+jinwei;

            //头插法反转链表
            ListNode temp = new ListNode(sum%10);
            temp.next = head;
            head = temp;

            jinwei = sum/10;

        }
        return head;
    
    }
}
```