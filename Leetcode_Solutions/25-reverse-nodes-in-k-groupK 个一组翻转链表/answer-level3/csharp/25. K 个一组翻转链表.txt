```
/**
    1、通过栈实现翻转
    2、记录每次翻转的起始位置，当翻转后将起始位置赋值nil
    3、链表入栈 每 K 次入栈进行一次翻转
    4、最后将新节点指向起始位置，修正新节点next
    
    当 k = 3 时，应当返回: 3->2->1->4->5
*/
public class Solution {
    public ListNode ReverseKGroup(ListNode head, int k) {
        if (k == 1) {
            return head;
        }
        Stack<ListNode> stack = new Stack<ListNode>();
        ListNode pre = new ListNode(-1);
        ListNode node = pre;
        ListNode cur = head, first = null;
        while (cur != null) {
            // 找到翻转的起始点
            if (stack.Count == 0) {
                first = cur;
            }
            stack.Push(cur);
            cur = cur.next;
            if (stack.Count == k) {
                // -1->3->2->1->2  node = 1
                while (stack.Count != 0) {
                    node.next = stack.Pop();
                    node = node.next;
                }
                first = null;
            }
        }
        // first: 4->5 || null
        node.next = first;
        return pre.next;
    }
}
// Accepted
//     81/81 cases passed (124 ms)
//     Your runtime beats 44.26 % of csharp submissions
//     Your memory usage beats 8.33 % of csharp submissions (25.7 MB)
```
