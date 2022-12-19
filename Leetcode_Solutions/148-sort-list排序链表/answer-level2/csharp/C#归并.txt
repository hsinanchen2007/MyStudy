### 解题思路
归并排序思想

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
    public ListNode SortList(ListNode head)
{
    return MergeSort(head, null);        
}

private ListNode MergeSort(ListNode head, ListNode tail)
{
    if(head == tail)
    {
        return head;
    }

    var slow = head;
    var fast = head;
    while(fast != tail && fast.next != tail)
    {
        slow = slow.next;
        fast = fast.next.next;
    }
    var temp = slow.next;
    slow.next = null;
    var left = MergeSort(head, slow);
    var right = MergeSort(temp, tail);
    ListNode guardNode = new ListNode(0);
    var preNode = guardNode;
    while(left != null && right != null)
    {
        if(left.val > right.val)
        {
            preNode.next = right;
            right = right.next;
        }else
        {
            preNode.next = left;
            left = left.next;
        }
        preNode = preNode.next;
    }
    preNode.next = left == null ? right : left;
    
    return guardNode.next;
}
}
```