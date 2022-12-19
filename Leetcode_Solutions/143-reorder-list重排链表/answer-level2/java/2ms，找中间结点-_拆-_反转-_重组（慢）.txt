![image.png](https://pic.leetcode-cn.com/42c5fc50cb61831b1ce73c936e955c66b2b7586ac77c7fdb9ef24d6ec511c0b7-image.png)

```
class Solution {
    public void reorderList(ListNode head) {
        //特殊处理
        if(head == null || head.next == null){
            return;
        }
        //快慢指针变量
        ListNode pf = head;
        ListNode ps = head;
        //快慢指针找中间结点
        while(pf != null && pf.next != null){
            ps = ps.next;
            pf = pf.next.next;
        }
        //ps.next就是中间节点
        //将其拆开成两个
        ListNode p = ps.next;
        ps.next = null;
        ListNode headN = new ListNode(0);
        
        //反转拆开的后一半链表，头插法
        while(p != null){
            ListNode n = new ListNode(p.val);
            n.next = headN.next;
            headN.next = n;
            p = p.next;
        }
        //得到两个链表开始重新拼接
        ListNode m = head;
        ListNode mN = headN.next;
        while (mN != null){
            ListNode tempm = m.next;
            ListNode tempmN = mN.next;
            m.next = mN;
            mN.next = tempm;
            m = tempm;
            mN = tempmN;
        }
    }
}
```
