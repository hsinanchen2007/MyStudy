### 解题思路
比较简单，代码如下

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

        ListNode finish = new ListNode(0);
        ljadd(l1,l2,finish,null,0);
        return finish;
    }

    void ljadd(ListNode l1,ListNode l2,ListNode parent,ListNode my,int w)
    {
        if (l1 == null && l2 == null)
        {
             if (w > 0)
                parent.val = w;
            else
                my.next = null;
            return;
        }
            

        int temp=0;
        ListNode node = new ListNode(0);
        parent.next = node;
        if (l1 == null)
        {
            temp = l2.val + w;
        }
        else if (l2 == null)
        {
            temp = l1.val + w;
        }
        else
        {
            temp = l1.val+l2.val + w;
        }
        parent.val = temp % 10;
        w = temp / 10;
        if(l1!=null)
        l1 = l1.next;
        if(l2!=null)
        l2 = l2.next;
        ljadd(l1, l2, node,parent, w);

    }
}
```