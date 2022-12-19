
### 解题思路
暴力法：遍历所有链表，并且结点的值放到一个 int 列表中；之后，对此列表排序，并根据排序后的列表创建新的链表

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
        if(lists.Length == 0) return null;
        List<int> items = new List<int>();

        ListNode curr = null;
        for(int i = 0;i<lists.Length;i++)
        {
            curr = lists[i];
            while(curr !=null)
            {
                items.Add(curr.val);
                curr = curr.next;
            }
        }

        items.Sort();
        if(items.Count==0)
        {
            return null;
        }
        
        ListNode head = new ListNode(items[0]);
        curr = head;
        for(int i= 1;i<items.Count;i++)
        {
            curr.next = new ListNode(items[i]);
            curr = curr.next;
        }

        return head;
    }
}
```


### 解题思路
分治法：以两个链表合并为思路，定义一个空链表，将它与第一个链表合并，并将结果与第二个继续合并，以此类推。

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
        if(lists.Length == 0) return null;
        if(lists.Length == 1) return lists[0];

        ListNode result = null;
        for(int i = 0; i < lists.Length; i++)
        {
            result = Merge2List(result,lists[i]);
        }

        return result;
    }

    private ListNode Merge2List(ListNode l1, ListNode l2)
    {
        if(l1 == null) return l2;
        if(l2 == null) return l1;

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while(l1!=null && l2 != null)
        {
            if(l1.val>l2.val)
            {
                  curr.next = l2;
                  l2 = l2.next;
            }
            else
            {
                curr.next = l1;
                l1= l1.next;
            }

            curr = curr.next;          
        }

        curr.next = l1==null? l2:l1;
        return dummy.next;
    }
}
```