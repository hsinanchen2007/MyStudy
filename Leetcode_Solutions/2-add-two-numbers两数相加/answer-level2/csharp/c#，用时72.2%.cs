### 解题思路
整体思路与官方解答一致，额外优化点：如果一个链表结束且没有进位，则将res.next指向活着的链表位置。

执行用时 :
72.20%
内存消耗 :
5.07%

PS:邀请大神指点一下内存优化。。。

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
            ListNode res_now;
            ListNode res;

            var sum = l1.val + l2.val;
            res_now = new ListNode(sum % 10);
            var carry_flag = sum / 10;

            res = res_now;

            while(true)
            {
                if(l1!=null)
                    l1 = l1.next;
                if(l2!=null)
                    l2 = l2.next;

                var l1_val = l1 == null ? 0 : l1.val;
                var l2_val = l2 == null ? 0 : l2.val;

                if (l1 == null & l2 == null & carry_flag == 0)
                    break;
                else if(l1 ==null & l2 ==null)
                {
                    ListNode next = new ListNode(carry_flag);
                    carry_flag = 0;
                    res_now.next = next;
                    res_now = next;
                }
                else if(l1==null && carry_flag == 0)
                {
                    res_now.next = l2;
                    break;
                }
                else if(l2 == null && carry_flag == 0)
                {
                    res_now.next = l1;
                    break;
                }
                else
                {
                    sum = l1_val + l2_val + carry_flag;
                    ListNode next = new ListNode(sum % 10);
                    carry_flag = sum / 10;

                    res_now.next = next;
                    res_now = next;
                }

            }

            return res;
    }
}
```