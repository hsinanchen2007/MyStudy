第一次写题解~还有点紧张，因为自己写了一遍就通过了，所以想要分享给大家一下~

解题思路：
K个一组翻转链表，具体到每一段，其实就是一个简单的翻转链表的问题
所以我们只需要将每一个段翻转的头结点返回，拼接到前一段的翻转后的尾结点即可
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null) return null;
        ListNode cur = head;
        int i = k;
        // 先遍历找到下一段的开头
        while(i>0&&cur!=null){
            cur = cur.next;
            i--;
        }
        // 如果没有到k个，那么原顺序返回
        if(i>0) return head;
        // 关键在于这个位置，返回值拼接到当前段翻转后的尾结点即可
        // 而尾结点就是原链表在当前段的头
        ListNode pre = reverseKGroup(cur,k);
        cur = head;
        i = k;
        while(i>0){
            ListNode tmp = cur.next;
            cur.next= pre;
            pre = cur;
            cur = tmp;
            i--;
        }
        return pre;
        
        
    }
}
```
