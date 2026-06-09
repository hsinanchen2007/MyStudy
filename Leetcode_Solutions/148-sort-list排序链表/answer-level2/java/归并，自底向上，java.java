```
class Solution {
    public ListNode sortList(ListNode head) {
        int len = 0;
        ListNode p = head;
        while(p != null){
            p = p.next;
            ++len;
        }
        for(int space = 1;space < len;space*=2){
            ListNode s1 = head;
            ListNode s2 = nextS(s1,space);
            ListNode pre = new ListNode(0),t = pre;
            while(s1 != null && s2 != null){
                int count1 = 0,count2 = 0;
                while(count1 < space && count2 < space && s1 != null && s2 != null){
                    if(s1.val <= s2.val){
                        pre.next = s1;
                        s1 = s1.next;
                        count1++;
                    }else{
                        pre.next = s2;
                        s2 = s2.next;
                        count2++;
                    }
                    pre = pre.next;
                }
                while(count1 < space && s1 != null){
                    pre.next = s1;
                    s1 = s1.next;
                    count1++;
                    pre = pre.next;
                }
                while(count2 < space && s2 != null){
                    pre.next = s2;
                    s2 = s2.next;
                    count2++;
                    pre = pre.next;
                }
                pre.next = s2;
                s1 = s2;
                s2 = nextS(s1,space);
            }
            head = t.next;
        }
        return head;
    }

    public ListNode nextS(ListNode c,int space){
        ListNode p = c;
        while(space > 0 && p!= null){
            --space;
            p = p.next;
        }
        return p;
    }

}
```
