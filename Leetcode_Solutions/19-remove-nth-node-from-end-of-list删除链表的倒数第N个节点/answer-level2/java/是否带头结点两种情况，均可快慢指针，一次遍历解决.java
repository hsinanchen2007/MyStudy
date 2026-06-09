
一次遍历，快慢指针即可。但是LeetCode采取的是没有虚拟头结点，也即头结点带有值。
这样就比较坑了，n个值就是n个节点，只有n-1个链，但是呢如果有虚拟头结点的话，n个值
就有n+1个节点，n个链。
先看带有虚拟头结点的情况：
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null){
            return null;
        }
        //用两个指针 第一个先走n部，因为有n个链，所以不会越界
        ListNode first = head;
        ListNode second = head;
        for (int i = 0; i < n; i++) {
            first = first.next;
        }
        while (first.next != null) {
            first = first.next;
            second = second.next;
        }
        //尾结点和非尾结点的情况是不一样的。
        //删除最后一个节点的情况：
        if (n == 1) {
            second.next = null;
        } else {
            //不是最后一个节点
            second.next = second.next.next;
        }
        return head;
    }
}
再看不带有虚拟头结点的情况【本题的情况】：
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return null;
        }
        //用两个指针 第一个走
        ListNode first = head;
        ListNode second = head;
        //当删除头结点的时候，实际上只有n个节点，n-1段链，就会溢出，溢出就说明是删除头结点
        for (int i = 0; i < n; i++) {
            first = first.next;
            if (first == null) {
                return second.next;
            }
        }
        while (first.next != null) {
            first = first.next;
            second = second.next;
        }
        //删除最后一个节点的情况：
        if (n == 1) {
            second.next = null;
        } else {
            //不是最后一个节点
            second.next = second.next.next;
        }

        return head;
    }
}