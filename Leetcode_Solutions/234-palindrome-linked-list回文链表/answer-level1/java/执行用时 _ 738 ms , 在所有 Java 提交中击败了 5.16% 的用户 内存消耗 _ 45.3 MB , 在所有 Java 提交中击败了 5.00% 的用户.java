### 解题思路
脑壳疼，这题说白了就是一个数在从后往前读每一个数字和从前往后读的每一个数字都相同，而我们需要做的只有两点，一、反转该链表，二、比较原来链表和反转后链表的每一个值是否相同，相同则是回文数，否则就不是，本题唯一问题就是如何保证原链表不被改变，我们使用List集合存储该链表即可，如何反转该链表这里就不说了，挺基础的东西，这里只给思路。

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
    public boolean isPalindrome(ListNode head) {
        List<Integer> list = new LinkedList<Integer>();
        int count = 0;
        ListNode dangqian = head;
        while(dangqian!=null) {
            list.add(dangqian.val);
            dangqian = dangqian.next;
            count++;
        }

        ListNode prev = null;
        ListNode current = head;
        ListNode next = null;
        while(current!=null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        int i = 0;
        while(i<count-1) {
            if(prev.val!=list.get(i)) {
                return false;
            }
            prev = prev.next;
            i++;
        }
        return true;
    }
}
```