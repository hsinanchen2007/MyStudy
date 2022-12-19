class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur=head;
        Map<Integer,Integer> map=new HashMap();
        List<Integer> list =new ArrayList<>();
        while(cur!=null){
            if(!map.containsKey(cur.val)){
                map.put(cur.val,1);
            }
            else{
                map.put(cur.val,map.get(cur.val)+1);
            }
            
            cur=cur.next;
        }

ListNode p=head;
while(p!=null){
    if(map.get(p.val)>1){list.add(p.val);}
    p=p.next;
}

        ListNode pre=new ListNode(-1);
        pre.next=head;
        ListNode hh=pre;
        ListNode z=head;
while(z!=null){
    if(!list.contains(z.val)){
        pre.next=z;
        pre=pre.next;
        z=z.next;
    }
    else{
        z=z.next;
        pre.next=null;
    }
}

return hh.next;










    }
}