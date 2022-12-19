循环遍历，两两比较形成一个有序新链表
```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length<1){
            return null;
        }
        if(lists.length==1){
            return lists[0];
        }
        ListNode l1 = lists[0];
        for(int i=1;i<lists.length;i++){
            l1 = this.mergeList(l1,lists[i]);
        }
        return l1;
    }
    private ListNode mergeList(ListNode l1,ListNode l2){
        if(l1 == null){
            return l2;
        }else if(l2 == null){
            return l1;
        }else if(l1.val<l2.val){
            l1.next = mergeList(l1.next,l2);
            return l1;
        }else{
            l2.next = mergeList(l1,l2.next);
            return l2;
        }
    }
}
```
