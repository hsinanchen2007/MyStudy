### 解题思路
此处撰写解题思路

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
        int n =lists.Length;
            ListNode head = new ListNode(0);
            var newList = head;
            int min=0;
            int subnum=0;
            bool flag = true;
            while (flag == true)
            {
                flag = false;
                for(int i=0;i<n;i++)
                {
                    if(lists[i]!=null && flag==false)
                    {
                        min = lists[i].val;
                        newList.next = lists[i];
                        subnum = i;
                        flag = true;
                        continue;
                    }
                    else if(lists[i]!=null)
                    {
                        if(lists[i].val<min)
                        {
                            min = lists[i].val;
                            newList.next = lists[i];
                            subnum = i;
                        }
                    }
                }
                if(flag==true)
                {
                    newList = newList.next;
                    lists[subnum] = lists[subnum].next;
                }
            }
            return head.next;
    }
}
```