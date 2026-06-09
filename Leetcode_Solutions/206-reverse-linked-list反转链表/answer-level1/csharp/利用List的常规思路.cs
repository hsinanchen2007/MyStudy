### 解题思路
既然要反转单链表，那就先使用一个List列表存储单链表里的全部数据，反转之后依次存入。

优化思路：反转和导入过程有重叠，可以合并。

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
    List<int> arr = new List<int>();
        public ListNode ReverseList(ListNode head)
        {
            ListNode newHead = head;
            while (head != null)
            {
                arr.Add(head.val);
                head = head.next;
            }
            head = newHead;
            arr.Reverse();
            for (int i = 0; i < arr.Count; i++)
            {
                newHead.val = arr[i];
                newHead = newHead.next;
            }
            return head;
        }
}
```