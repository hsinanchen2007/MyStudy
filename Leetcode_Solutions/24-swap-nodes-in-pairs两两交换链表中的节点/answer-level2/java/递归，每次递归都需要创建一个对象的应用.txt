### 解题思路
![ans.png](https://pic.leetcode-cn.com/f6d034821f4bd0e6ce28cc9165baae85f4ba14f13a35fe5a981e7a107832b249-ans.png)


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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode ans = head.next;
        head.next = head.next.next;
        ans.next = head;
        head.next = swapPairs(head.next);
        return ans;
    }
}
```