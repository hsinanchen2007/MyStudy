### 解题思路
此处撰写解题思路
    思路1、：从头开始，每次都将下一个列表放置头部，直到最后，即实现了链表的反转
    如：1->2->3->4->5->NULL
        2->**1**->3->4->5->NULL  3->2->**1**->4->5->null ... 
    思路2：可以将链表中的数据全部取出来，放入栈中，然后出栈，重新构造链表，也可以实现链表反转
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
    public ListNode ReverseList(ListNode head) {
        var curNode = head;
        while(curNode!=null && curNode.next!=null) {
            var nextNode = curNode.next;
            curNode.next = nextNode.next;
            nextNode.next = head;
            head = nextNode;
        }
        return head;


        // Stack<ListNode> stack = new Stack<ListNode>();
        // if(head==null)
        //     return null;
        // while(head!=null) {
        //     stack.Push(head);
        //     head = head.next;
        // }
        // ListNode dummpy = new ListNode(0);
        // ListNode temp = dummpy;
        // while(stack.Count!=0) {
        //     temp.next = new ListNode(stack.Pop().val);
        //     temp = temp.next;
        // }

        // return dummpy.next;
    }
}
```