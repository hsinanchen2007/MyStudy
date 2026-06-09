### 解题思路
一遍循环，创建一个新的链表存储返回，遇到重复的跳过就行。
时间复杂度O(n)
击败c#100%用户
![QQ截图20200130022615.jpg](https://pic.leetcode-cn.com/f098d30d1c9e27269053d68f39b8cb093b78807de62b1e14b456734e94038c63-QQ%E6%88%AA%E5%9B%BE20200130022615.jpg)

### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
            ListNode res = new ListNode(0),l1=res,l2=head;
            if(head==null||head.next==null)
                return head;
            
            while (l2.next != null)
            {
                if (l2.next.val != l2.val)
                {
                    l1.next = new ListNode(l2.val);
                    l1 = l1.next;
                    l2 = l2.next;
                    if(l2.next==null)
                        l1.next = new ListNode(l2.val);
                }
                else
                {
                    int num = l2.val;
                    while (l2.next != null&&l2.val == num)
                    {
                        l2 = l2.next;
                    }
                    if (l2.next == null&&l2.val!=num)
                        l1.next = new ListNode(l2.val);
                }
            }
            return res.next;
    }
}
```