
```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists==null){
            return null;
        }
        Queue<ListNode> merge = new PriorityQueue<ListNode>((x1, x2) -> x1.val - x2.val);
        for(int i=0;i<lists.length;i++){
            if(lists[i]!=null)
                merge.add(lists[i]);
        }
        ListNode head = new ListNode(0),p=head; 
        while(!merge.isEmpty()){
            p.next = merge.poll();
            p = p.next;
            if(p.next!=null)
                merge.add(p.next);
        }
        return head.next;
    }
}
```