

```

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //建立虚拟头结点
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        //基于比较 遍历两个链表
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                cur.next = l1;//cur指向更小的
                cur = cur.next;//cur起到串联的作用
                l1 = l1.next;// l1是比较的基准, 移动向下一个比较基准
            }else{
                cur.next = l2;
                cur = cur.next;
                l2 = l2.next;
            }
        }

        if(l1 != null)  cur.next = l1;
        else            cur.next = l2;

        return dummy.next;
    }

```

视频链接
https://www.bilibili.com/video/BV1J741137zx/
