### 解题思路
遍历一次链表并把节点存入数组中，然后计算出需要删掉节点的索引，并对头尾节点特殊处理。

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
    public ListNode RemoveNthFromEnd(ListNode head, int n)
        {
            List<ListNode> list = new List<ListNode>();
            while (head != null)
            {
                list.Add(head);
                head = head.next;
            }

            int index = list.Count - n;
            if (index == 0)
            {
                if (list.Count == 1)
                {
                    return null;
                }
                return list[1];
            }
            else if (index == list.Count - 1)
            {
                list[list.Count - 2].next = null;
                return list[0];
            }
            else
            {
                list[index - 1].next = list[index + 1];
                return list[0];
            }
        }
}
```