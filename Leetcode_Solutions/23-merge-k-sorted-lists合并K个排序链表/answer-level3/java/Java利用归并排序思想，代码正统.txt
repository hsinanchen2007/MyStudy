    ```
    public  ListNode mergeList(List<ListNode> list,int start,int end){
        if(start==end){
            return list.get(start);
        }
        int mid=(start+end)>>1;
        ListNode nodeLeft=mergeList(list,start,mid);
        ListNode nodeRight=mergeList(list,mid+1,end);
        return merge(nodeLeft,nodeRight);
    }

    public  ListNode merge(ListNode l1,ListNode l2){
        ListNode dummy=new ListNode(0);
        ListNode pre=dummy;
        while(l1!=null&&l2!=null){
            if(l1.val<=l2.val){
                pre.next=l1;
                l1=l1.next;
            }else{
                pre.next=l2;
                l2=l2.next;
            }
            pre=pre.next;
        }
        if(l1!=null){
            pre.next=l1;
        }
        if(l2!=null){
            pre.next=l2;
        }
        return dummy.next;
    }
```
