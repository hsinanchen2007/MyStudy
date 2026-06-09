### 代码

```java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode first=head;
        ListNode totalfirst=head;
        int num=0;
        for(;first!=null;first=first.next,num++);
        for(int i=0;i<(k-1);i++)
            totalfirst=totalfirst.next;
        int count=num/k;
        first=head;
        ListNode last;
        ListNode target;
        ListNode neofirst;
        for(int i=0;i<count;i++){
            last=row(first,k-1);
            neofirst=last.next;
            for(;first!=last;){
                target=first;
                for(;target.next!=last;)
                    target=row(target,1);  
                last.next=target;
                last=target;              
            }
            if(i==count-1){
                first.next=neofirst;
                break;
            }
            first.next=row(neofirst,k-1);
            first=neofirst;
        }
        return totalfirst;
    }
    public ListNode row(ListNode l,int times){
        ListNode p=l;
        for(int i=0;i<times;i++)
            p=p.next;
        return p;
    }
}

//尾插法：
/*
    cur=head.next;
    head.next=last.next;
    last.next=head;
    head=cur;
    if(head==last)
        break;
*/
//head=row(head,k);  last=row(last,k-1);   last.next=row(last,k);   last=row(last,k);
//如此下来时间复杂度为O(n);
```