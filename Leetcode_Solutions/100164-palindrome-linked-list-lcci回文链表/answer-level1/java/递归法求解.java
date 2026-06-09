回文串的特点：前半部分的值和后半部分颠倒的值相等。

利用递归，递归到链表的尾部，用 tail 值向尾部，然后回溯时，依次比较头结点 head 和 tail 的值，相等则 head 往下移动，不等则直接返回 false。

```
class Solution {
    // 标志位，如果为 true 时，则 head 向下移动
    boolean flag = false;
    // 全局变量 head，指向头结点
    ListNode head = null;
    public boolean isPalindrome(ListNode head) {
        if(head == null)
            return true;
        this.head = head;
        return recursion(head);
    }

    private boolean recursion( ListNode tail){
        if(tail == null){
            return true;
        }
        // 标志位，接收递归返回的值。
        flag = recursion(tail.next);
        // 如果 flag 为 true，则比较 head 和 tail的值
        if (flag){
            // head 和 tail 的值不相等 flag 则设为 false， 相等 head 向下移动
            if(head.val != tail.val)
                flag = false;
            else
                head = head.next;
        }
        return flag;
    }

}
```
