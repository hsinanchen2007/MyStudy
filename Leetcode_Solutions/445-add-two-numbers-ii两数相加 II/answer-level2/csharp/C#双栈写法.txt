### 解题思路
C#双栈写法

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
        Stack<int> s1 = new Stack<int>(); 
        Stack<int> s2 = new Stack<int>();
        while(l1!= null)
        {
            s1.Push(l1.val);
            l1 = l1.next;
        }
        while(l2 != null)
        {
            s2.Push(l2.val);
            l2 = l2.next;
        }
        
        int carry = 0;
        ListNode preNode = null;
        while(s1.Count > 0 || s2.Count >0)
        {
            var e1 = s1.Count > 0 ? s1.Pop() : 0;
            var e2 = s2.Count > 0 ? s2.Pop() : 0;
            var sum = e1 + e2 + carry;
            if(sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            var newNode = new ListNode(sum);
            newNode.next = preNode;
            preNode = newNode;
        }

        if(carry == 1)
        {
            var newNode = new ListNode(1);
            newNode.next = preNode;
            preNode = newNode;
        }

        return preNode;
    }
}
```