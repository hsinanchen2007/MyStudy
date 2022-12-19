### 解题思路
思路：双指针，数学证明略
![image.png](https://pic.leetcode-cn.com/f4c2c02b420b1ac7b3e68bf6f31f531ee6a451effbe5f38296e318e19e8713b5-image.png)

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {     //如果使用额外空间，可以使用一个哈希表，不使用额外空间，双指针
    public ListNode detectCycle(ListNode head) {
        if(head == null)
            return null;
        ListNode dummy1 = new ListNode(-1);
        ListNode dummy2 = new ListNode(-2);
        dummy1.next = head;
        dummy2.next = head;
        ListNode slow = dummy1;
        ListNode fast = dummy2;
        while(slow != fast){    //找到环上相遇的点
            if(fast == null || fast.next == null)
                return null;    //无环,返回null
            slow = slow.next;
            fast = fast.next.next;
        }
        //然后让fast回到dummy点与slow以相同的速度前进，则相遇的点即为环的入口点
        fast = dummy2;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}
```