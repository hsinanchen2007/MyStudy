```
  public ListNode reverseKGroup(ListNode head, int k) {

        ListNode retPre = null;
        ListNode cur = head;
        ListNode retEnd = head;
        while (cur!=null){
            ListNode pre = null;
            ListNode start = cur;
            ListNode end = cur;
            boolean flag = checkReverseKGroup(end,k);
            if(!flag){
                if(retPre != null){
                    retEnd.next = cur;
                    return retPre;
                }else {
                    return head;
                }
            }
            for(int i = 0 ; i < k ;i++){
                ListNode tempNext = cur.next;
                cur.next = pre;
                pre = cur;
                cur = tempNext;
            }
            if(retPre == null){
                retPre=pre;
                retEnd.next = cur;
            }else {
                retEnd.next = pre;
                retEnd = start;
            }

        }

       return retPre;
    }

    private boolean checkReverseKGroup(ListNode end, int k) {
        for(int i = 0 ; i < k-1 ; i++){
            if(end == null){
                return false;
            }
            end = end.next;
        }
        if(end == null){
            return false;
        }
        return true;
    }

```
