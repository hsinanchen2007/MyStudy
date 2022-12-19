    public void reorderList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null)
            return;
        
        //1.快慢指针，找到链表中点
        ListNode slow = head;
        ListNode fast = head.next.next;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }//此刻，slow指向链表中点L((n-1)/2)
        
        //2.将链表后一半原地逆置
        ListNode p = slow.next;
        ListNode q = p.next;
        p.next = null;
        
        while(q != null){
            ListNode r = q.next;
            q.next = p;
            p = q;
            q = r;  
        }
        slow.next = null;
        
        //3.将 以head为头结点的链表 和 以p为头结点的链表 合并
        q = p.next;
        ListNode r = head;
        ListNode s = r.next;
        
        while(r.next != null && p.next != null){
            r.next = p; r = s; s = s.next;
            p.next = r; p = q; q = q.next;
        }
        r.next = p;
    }