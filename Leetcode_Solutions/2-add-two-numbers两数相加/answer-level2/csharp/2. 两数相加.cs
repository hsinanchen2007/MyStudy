

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
   public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode result = new ListNode(0);
            ListNode tempNode = result;

            int carry = 0;
            while (l1 != null || l2 != null || carry != 0)
            {
                int sum = 0;
                ListNode node = new ListNode(0);

                sum = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;

                if (sum >= 10)
                {
                    carry = 1;
                    node.val = sum % 10;
                }
                else
                {
                    carry = 0;
                    node.val = sum;
                }

                l1 = l1?.next;
                l2 = l2?.next;

                tempNode.next = node;
                tempNode = tempNode.next;
            }

            return result.next;
        }
}
```