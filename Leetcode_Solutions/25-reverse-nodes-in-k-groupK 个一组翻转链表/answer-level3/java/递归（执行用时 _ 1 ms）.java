```
public ListNode reverseKGroup(ListNode head, int k) {
        //用来判断最后一组是否等于指定长度，如果不等于指定长度则直接返回head，不用反转
        //如果不用这部分则会将最后一组数据也进行反转
        ListNode tempnode = head;
        int temp = 1;
        while(tempnode!=null && temp<k){
            tempnode=tempnode.next;
            temp++;
        }
        if(tempnode==null){
            return head;
        }
            
        //以下代码会将所有长度等于k的链翻转
        ListNode pre = null;
        ListNode curr = head;
        ListNode left = head.next;
        int tk =k;
        while (curr != null && tk != 0) {
            curr.next = pre;
            pre = curr;
            curr = left;
            if (curr == null) return pre; else left = curr.next;
            tk--;
        }
        head.next = reverseKGroup(curr, k);
        return pre;
    }
```
