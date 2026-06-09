两层循环，第一层判断要不要继续下一次k个旋转
第二层用来k个旋转，用头插法来实现
利用第二层循环的i值判断够不够k个，不够k个再讲其头插


class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode xhead=new ListNode(0);
        ListNode tail=xhead,p=head,work;
        if(k==1)return head;
        if(head==null)return head;
        xhead.next=head;
        int n=k,i=0;
        while(p!=null)
        {
            n=k;
            
            for(i=0;i<n-1&&p.next!=null;i++)
            {
              work=tail.next;
                tail.next=p.next;
                p.next=p.next.next;
                tail.next.next=work;
            }
            if(i==n-1) 
            tail=p;
            p=p.next;
         
        }
        if(i!=n-1)
        {
            p=tail.next;
            while(p.next!=null)
            {work=tail.next;
                tail.next=p.next;
                p.next=p.next.next;
                tail.next.next=work;
            }
        }
        return xhead.next;
    }
}