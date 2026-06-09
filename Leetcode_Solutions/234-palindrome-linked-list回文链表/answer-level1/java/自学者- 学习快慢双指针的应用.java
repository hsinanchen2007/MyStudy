### 解题思路
* 快慢指针概念和基本应用，相关概念：中位数，奇偶不同判断理论
* 移动中记录两个反转指针，这个比较难以理解
  * prev对齐的是slow慢指针
  * beforePrev对齐的也是慢指针的前一个
  * 采用快指针步进，那么慢指针停留在奇数节点的中间位置或者偶数节点中间的前一个位置
  * 第二个循环采用慢指针步进作为后半段的起点
  * 对比从中间位置开始往两边发展
  
* 1个节点或者不给节点时要返回true
* 两个循环都是步进半数，所以时间复杂度和空间复杂度完全符合要求

### 思考
* 采用堆栈模式是否超过空间复杂度？ 答案：肯定，b

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
        if (head == null || head.next == null) {
            return true;
        }

        //快慢指针
        ListNode fast = head;
        ListNode slow = head;
        //链表反转
        ListNode prev = head;
        ListNode beforePrev = null;
        while (fast != null && fast.next != null) {
            //快指针决定是否停止循环
            prev = slow;
            //快慢指针步进
            slow = slow.next;
            fast = fast.next.next;
            prev.next = beforePrev;
            beforePrev = prev;
        }
        if (fast != null) {
            //奇数个节点判，断后半部分即可。
            slow = slow.next;
        }
        while (prev != null && slow != null) {
            if(prev.val != slow.val) {
                return false;
            }
            prev = prev.next;
            slow = slow.next;
        }
        return true;
    }
}
```