### 解题思路
前面有类似的题目。主题思想就是把回文数颠倒再比较，相同就是回文数，否则不是

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
        int length=0;
        List<Integer> list = new LinkedList<Integer>();
        ListNode now = head;
        while(now!=null) {
            list.add(now.val);
            now = now.next;
            length++;
        }
        ListNode current = head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        while(current!=null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        int i = 0;
        while(i<length-1) {
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