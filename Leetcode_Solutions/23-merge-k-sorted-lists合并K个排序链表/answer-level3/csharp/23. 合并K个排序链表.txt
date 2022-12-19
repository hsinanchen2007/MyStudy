### 解题思路
使用 HashSet 缓存非空链表的索引

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
    public ListNode MergeKLists(ListNode[] lists) {
        if (lists.Length == 0 || lists.Length == 1)
        {
            return lists.FirstOrDefault();
        }

        HashSet<int> unemptyList = new HashSet<int>();
        for (int index = 0; index < lists.Length; index++)
        {
            if (lists[index] != null)
            {
                unemptyList.Add(index);
            }
        }

        var dummy = new ListNode(0);
        var current = dummy;
        while (unemptyList.Count > 0)
        {
            var minIndex = unemptyList.First();
            var minValue = lists[minIndex].val;
            foreach (var index in unemptyList)
            {
                if (minValue > lists[index].val)
                {
                    minValue = lists[index].val;
                    minIndex = index;
                }
            }

            lists[minIndex] = lists[minIndex].next;
            if (lists[minIndex] == null)
            {
                unemptyList.Remove(minIndex);
            }

            current.next = new ListNode(minValue);
            current = current.next;
        }

        return dummy.next;
    }
}
```