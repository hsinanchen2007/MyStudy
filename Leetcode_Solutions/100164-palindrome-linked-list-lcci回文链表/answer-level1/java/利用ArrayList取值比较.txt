### 解题思路
1.将链表所有值储存在List里
2.对list进行首尾比较
3.如果为回文则应首尾相同，依次类推
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
        ArrayList<Integer> list = new ArrayList<>();
        while(head != null) {
            list.add(head.val);
            head = head.next;
        }
        int len = list.size();
        for(int i = 0; i < list.size() / 2; i++) {
            int a = list.get(i);
            int b = list.get(--len);
            if(a != b) {
                return false;
            }
        }
        return true;
    }
}
```