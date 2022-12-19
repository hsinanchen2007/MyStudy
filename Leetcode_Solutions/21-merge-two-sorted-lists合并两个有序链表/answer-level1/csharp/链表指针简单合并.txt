### 解题思路
该题题意的点就是 合并 两个有序链表  既然有顺序那就去掉了最难的环节
假设我创建一个链表用来存储合并好的链表
然后创建一个指针 指向我本次操作到了哪一个节点

用while做循环读取 每次的结果都存储到指针 然后指针切换到指针的下一个节点

while里面的条件结束以两个链表读取完结束

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
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
           ListNode nodeall = new ListNode(0);
            ListNode node = nodeall;

            while (l1 != null || l2 != null)
            {
                if(l1!=null && l2 != null)
                {
                    if (l1.val > l2.val)
                    {
                        node.next = new ListNode(l2.val);
                        l2 = l2.next;
                    }
                    else
                    {
                        node.next = new ListNode(l1.val);
                        l1 = l1.next;
                    }

                }else if (l1 != null)
                {
                    node.next = new ListNode(l1.val);
                    l1 = l1.next;
                }
                else
                {
                    node.next = new ListNode(l2.val);
                    l2 = l2.next;
                }
                node = node.next;
            }
            return nodeall.next;
    }
}
```