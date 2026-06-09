### 解题思路
思路就是分奇偶链表，但要注意一定要将偶链表最后指向null，不然就成环了

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
   public ListNode oddEvenList(ListNode head) {

       if (head == null||head.next==null){
            return head;
        }

        ListNode headValue = head;
        ListNode headE = head.next;
        ListNode odd = head;
        ListNode even = head.next;
        head = head.next.next;

       boolean flag = false;
       while (head!=null) {
            if (!flag){
                odd.next = head;
                head = head.next;
                odd = odd.next;
                flag = true;
            }else {
                even.next = head;
                head = head.next;
                even = even.next;

                flag = false;
            }
        }
        odd.next = headE;
        even.next = null;
        return headValue;
        
    }
}
```