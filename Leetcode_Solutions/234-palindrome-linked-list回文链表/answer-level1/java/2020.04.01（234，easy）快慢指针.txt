### 解题思路
本题思路和`143`题很相似，区别就在于本题的最后会**比较两段链表的值是否相等**也就是判断是不是回文

- `143`题找链表的中间位置是先求出**链表长度**再从头移动一半的长度，而本题使用了**快慢指针**寻找更加方便

- 其他操作比如断链，逆序都是一样的

- **不同**就在于逆序后的链表需要和前一半的链表元素值挨个**比较看是否相等**

- 无论链表元素是**奇数个还是偶数个**，如果在比较过程中有不相等的直接就返回`false`

- **若有一方遍历结束**还没返回`false`则证明两部分元素值是一样的，返回`true`即可。

### 代码

```java []
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
        if (head == null || head.next == null) {
            return true;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // 定义快慢指针
        ListNode slow = dummy;
        ListNode fast = dummy;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode tmp = slow.next;
        slow.next = null;
        
        // 反转后一半链表
        ListNode newHead = reverse(tmp);
        
        // 比较两链表是否一致
        while (head != null && newHead != null) {
            if (newHead.val != head.val) {
                return false;
            }
            head = head.next;
            newHead = newHead.next;  
        }
        return true;
    }
    
    private ListNode reverse(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode pre = head;
        head = head.next;
        pre.next = null;
        while (head != null) {            
            ListNode p = head.next;
            head.next = pre;
            pre = head;
            head = p;
        }
        return pre;
    }
}
```