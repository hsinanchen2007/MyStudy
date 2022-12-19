### 解题思路
反转链接后相加，具体思路见注释

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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null) return null;
        if(l1 == null || l2 == null) return l1 == null? l2: l1;
        var r1= reverse(l1);
        var r2= reverse(l2);

        // c1,c2为反转后两个链表的头指针
        ListNode c1 = r1;
        ListNode c2 = r2;
        int carry = 0;  // 进位
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;     
        while(c1 != null || c2 != null)
        {
            // 取得待相加的两位
            int n1 = c1 != null ? c1.val : 0;
            int n2 = c2 != null ? c2.val : 0;

            // 相加并得到进位（result / 10)以及当前节点的值（result % 10)
            int result = n1 + n2 + carry;           
            carry = result / 10;

            ListNode newNode = new ListNode(result % 10);
            curr.next = newNode;

            // 三个指针同时向前进，需要注意的是，由于链接的长度可能不同，所以要判断一下 c1 和 c2 是否为空
            curr = curr.next;
            c1 = c1 == null? null: c1.next ;
            c2 = c2 == null? null: c2.next;
        }

        // 再检查一下最后一次相加是否有进位
        if(carry == 1)
        {
            curr.next = new ListNode(1);
        }

        // 从 dummy 节点的下一节点开始反转即为结果
        return reverse(dummy.next);
    }

    // 反转链表
    private ListNode reverse(ListNode m1)
    {
        if( m1 == null) return null;
        ListNode pre = null;
        ListNode curr = m1;
        while(curr != null)
        {
            ListNode next = curr.next;

            curr.next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }
}
```