class Solution {
    public int kthToLast(ListNode head, int k) {
        ListNode origin = head;
        int length = 0;
        while(head.next!=null){
            head = head.next;
            length++;
        }
        // 确定链表长度
        length++;
        // 正向计算目标点所在位置
        int time = 0;
        while(length-k>time){
            time++;
            origin = origin.next;
        }
        return origin.val;
    }
}