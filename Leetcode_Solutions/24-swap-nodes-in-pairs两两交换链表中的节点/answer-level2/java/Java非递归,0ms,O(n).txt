- 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
- 内存消耗 :34.2 MB, 在所有 Java 提交中击败了87.62%的用户

代码有全部注释,易于理解:
```Java []
class Solution {
    
    
    /**
     * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
     * 非递归,O(n)
     * @param head
     * @return
     */
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null) return head;
        //pre是前一个节点,next是后一个节点,tmphead保存第一次的头节点,tmp保存上一次的尾节点,p是移动指标
        ListNode pre = null,next,tmphead = null,tmp = null,p = head;
        int i = 0;
        while (p != null && p.next != null) {
            //保存上一次的尾节点
            if (i > 0) tmp = pre;
            //交换
            pre = p;
            next = p.next;
            pre.next = next.next;
            next.next = pre;
            //只需要移到下一个节点即可
            p = pre.next;
            //上一次的尾节点链上这次的头节点
            if (i > 0) tmp.next = next;
            //保存第一次的头节点
            if (i == 0) tmphead = next;
            i++;
        }
        return tmphead;
    }
}
```
