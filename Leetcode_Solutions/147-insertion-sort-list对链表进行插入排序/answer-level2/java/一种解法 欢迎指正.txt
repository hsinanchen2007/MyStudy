public ListNode insertionSortList(ListNode head) {

        if (head==null){
            return null;
        }
        ListNode now = head;

        while (now.next!=null){
            //下一个比now大直接位移一位
            if (now.next.val>=now.val){
                now = now.next;
                continue;
            }
            ListNode tmp = now.next;
            if (now.next.next!=null){
                now.next=now.next.next;
            }else {
                now.next=null;
            }

            if (tmp.val<head.val){
                tmp.next=head;
                head = tmp;
            }else {
                ListNode tmp2 = head;
                while (tmp2.next!=null&&tmp.val>tmp2.next.val){
                    tmp2 = tmp2.next;
                }
                tmp.next = tmp2.next;
                tmp2.next=tmp;
            }

        }
        return head;
    }