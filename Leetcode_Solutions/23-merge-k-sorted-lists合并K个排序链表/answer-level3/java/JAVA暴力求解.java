只会暴力求解的我。。。。

```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < lists.length; i++){
            while(lists[i]!=null){
                list.add(lists[i].val);
                lists[i] = lists[i].next;
            }
        }
        Collections.sort(list);
        if(list.size() == 0)return
        ListNode node = new ListNode(list.get(0));
        ListNode p = node;
        for(int i = 1; i < list.size(); i++){
            node.next = new ListNode(list.get(i));
            node = node.next;
        }
        return p;
    }
}
```
