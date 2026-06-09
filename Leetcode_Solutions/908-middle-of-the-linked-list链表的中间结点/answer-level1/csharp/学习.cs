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
    public ListNode MiddleNode(ListNode head) 
    {
     //第一种数组存储的方式
    //   if(head.next==null)
    //   return head;

    //   List<ListNode> list=new List<ListNode>();
    //   ListNode node=head;

    //   do
    //   {
    //       list.Add(node);
    //       node=node.next;
    //   }
    //   while(node!=null);

    //   return list[list.Count/2];

    // 使用快慢指针的形式
     ListNode runNode=head;
     ListNode pointer=head;
     int count =0;
     while(runNode!=null)
     {
        if(count==0)
        {
            count++;
        }
        else
        {
            pointer=pointer.next;
            count--;
        }
        runNode=runNode.next;
     }
 
 return pointer;
    }
}
```