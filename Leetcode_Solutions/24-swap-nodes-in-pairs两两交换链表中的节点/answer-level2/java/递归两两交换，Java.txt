官方题解没怎么看懂，我自己草稿纸上画，然后代码就出来了，通过之后也很高兴...
```
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;

        //第一个节点
        ListNode first = head;
        //第二个节点
        ListNode second = head.next;

        //保存记录第二个节点后的节点引用
        ListNode next = second.next;

        //第二个节点指向第一个节点
        second.next = first;

        //第二个节点指向第一个节点，第一个节点指向(原第二个节点的下一个节点)
        first.next = swapPairs(next);

        return second;
    }
}
```
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :34 MB, 在所有 Java 提交中击败了89.88%的用户


