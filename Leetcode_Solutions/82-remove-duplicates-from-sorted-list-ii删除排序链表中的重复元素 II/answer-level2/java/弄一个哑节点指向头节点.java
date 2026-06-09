### 解题思路
此处撰写解题思路

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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null){
            return head;
        }

        ListNode tmp = head;
        ListNode Yummy = new ListNode(0);
        Yummy.next = head;

        ListNode pre = Yummy;
        boolean flag = false;
        while(tmp.next!=null){
            
            while (tmp.next != null && tmp.val == tmp.next.val){
                tmp.next = tmp.next.next;
                flag = true;
            }
            if (flag){
                pre.next = tmp.next;
                flag = false;
            }else{
                pre = tmp;
            }
            tmp = tmp.next;
            if (tmp == null){
                return Yummy.next;
            }
        }

        return Yummy.next;

    }
}
```