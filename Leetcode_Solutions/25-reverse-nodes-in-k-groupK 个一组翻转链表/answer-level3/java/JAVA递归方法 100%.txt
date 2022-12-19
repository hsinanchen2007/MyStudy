思路如下：
1.依据k找到即将要翻转的k个节点的起点和终点（不满k个不翻转）
2.利用双指针方法对起点和终点区间内的节点进行翻转
3.递归调用处理后续节点
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k==0) return head;
        int temp=k;
        ListNode p =head;
        while(temp>1){
            if(p==null) break;
            p=p.next;
            temp--;
        }
        if(p==null) return head;
        ListNode head_pre=head,pNext_pre=p.next;
        head =reverseList(head,p); p =head_pre;
        p.next=reverseKGroup(pNext_pre,k);
        return head;
    }
    public ListNode reverseList(ListNode head,ListNode endNode) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode end=endNode.next;
        while(cur!=end){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return  pre;
    }
}
```
