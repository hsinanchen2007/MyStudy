```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int a = Integer.MAX_VALUE;
        int index = -1; 
        ListNode pre = null;
        for(int i = 0; i < lists.length; i ++){
            if(lists[i] != null){
                if(a > lists[i].val){
                    a = lists[i].val;
                    index = i;
                }
            }
        }
        if(index != -1){
            pre = lists[index];
            lists[index] = lists[index].next;
            pre.next = mergeKLists(lists);
        }
        return pre;
    }
}
```


