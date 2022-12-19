### 解题思路
链表反转 + 两数相加1的思路

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

        ListNode link1 = reverse(l1);
        ListNode link2 = reverse(l2);
        ListNode result = new ListNode(-1);
        ListNode cur = result;
        boolean flag = false;

        while((link1!=null)||(link2!=null)){
            int temp1 = link1==null?0:link1.val;
            int temp2 = link2==null?0:link2.val;
            int sum = temp1+temp2;
            if(flag){
                sum++;
            }
            if(sum >= 10){
                flag = true;
                sum%=10;
            }else{
                flag = false;
            }
            
            cur.next = new ListNode(sum);
            cur = cur.next;
            if(link1!=null){
                link1 = link1.next;
            }
            if(link2!=null){
                link2 = link2.next;
            }
        }

        if(flag){
            cur.next = new ListNode(1);
        }

        
        return reverse(result.next);
    }

    private ListNode reverse(ListNode node){
        if(node==null||node.next==null){
            return node;
        }
        ListNode pre = reverse(node.next);
        node.next.next = node;
        node.next = null;
        return pre;
    }   
}
```