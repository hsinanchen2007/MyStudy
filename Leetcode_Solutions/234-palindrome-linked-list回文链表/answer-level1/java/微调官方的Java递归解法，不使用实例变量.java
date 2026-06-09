官方题解中的递归解法，使用了实例变量。但我个人觉得，实现工具类时，方法不依赖类的成员变量会更好。
此时，重点有：
1. 当递推进行到最内层时，我们无法再从类成员变量中获得用于正向遍历的引用frontPointer，所以，应当将该引用frontPointer作为参数传递给递归方法并层层**透传**。
2. 不断向前推进的frontPointer需要由递归方法来返回，从而上层调用可以访问到对应的节点值。
3. 如果当前回归层次的节点值不相等，即链表已经得证非回文，则返回null。
4. 最终的结果由递归调用的返回值是否为null来决定。
5. 用于前后向遍历的两个引用会分别遍历整个链表一趟，在到达尾/头节点时要注意next==null这个事实和最终逻辑结果的歧义。
```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        return isPalindrome(head, head) != null;
    }

    private ListNode isPalindrome(ListNode cur, ListNode head) {
        if (cur != null) {
            ListNode correspond = isPalindrome(cur.next, head);
            if (correspond != null && cur.val == correspond.val) {
                if (correspond.next != null) return correspond.next;
                return cur;
            }
            return null;
        }
        return head;
    }
}
```
