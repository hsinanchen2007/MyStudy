为了实现O(1)的空间效率，不能用栈
但是回文判断需要知道中间节点，然后双指针才能实现O(n)+O(1)的效率
参考的其他答案，提供C#版本的代码
```
public class Solution
{
    public bool IsPalindrome(ListNode head)
    {
        if (head == null) return true;
        ListNode slow = head, fast = head;
        ListNode prev = null, prePrev = null;
        while (fast != null && fast.next != null)
        {
            prePrev = prev;
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
            prev.next = prePrev;
        }
        if (fast != null)
        {
            slow = slow.next;
        }
        while (slow != null)
        {
            if (slow.val != prev.val) return false;
            slow = slow.next;
            prev = prev.next;
        }
        return true;
    }
}
```
