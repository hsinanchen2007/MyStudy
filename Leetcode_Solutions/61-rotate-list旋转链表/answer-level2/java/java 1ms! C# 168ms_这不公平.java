没有想到形成环形，跟官方解法差不多的思想但是没那么优雅。
思想是：用最少的操作计算出链表长度n，并且把fast指针移动到k处。
第一步遍历k步，如果`fast != null`说明`k<n`
如果`fast == null`说明k大于n，`k = k % n`，然后进而fast走k步
到这里可以保证fast处在第k位
开始双指针
```java []
class Solution
{
    public ListNode rotateRight(ListNode head, int k)
    {
        if (head == null || head.next == null) return head;
        ListNode fast = head;
        int len = 0;
        while (k > 0 && fast != null)
        {
            fast = fast.next;
            len++;
            k--;
        }
        if (fast == null)
        {
            k = k % len;
            fast = head;
            while (k > 0)
            {
                fast = fast.next;
                k--;
            }
        }
        ListNode slow = head;
        while (fast.next != null)
        {
            fast = fast.next;
            slow = slow.next;
        }
        fast.next = head;
        head = slow.next;
        slow.next = null;
        return head;
    }
}
```
```C# []
public class Solution
{
    public ListNode RotateRight(ListNode head, int k)
    {
        if (head == null || head.next == null) return head;
        ListNode fast = head;
        int len = 0;
        while (k > 0 && fast != null)
        {
            fast = fast.next;
            len++;
            k--;
        }
        if (fast == null)
        {
            k = k % len;
            fast = head;
            while (k > 0)
            {
                fast = fast.next;
                k--;
            }
        }
        ListNode slow = head;
        while (fast.next != null)
        {
            fast = fast.next;
            slow = slow.next;
        }
        fast.next = head;
        head = slow.next;
        slow.next = null;
        return head;
    }
}
```
