```
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> nodesQueue = new PriorityQueue<>(new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return o1.val-o2.val;
            }
        });

        ListNode head = new ListNode(0);
        for(ListNode node:lists)
            if(node!=null)
                nodesQueue.add(node);

        ListNode p = head;
        while(!nodesQueue.isEmpty()){
            if(nodesQueue.peek().next==null){
                p.next = new ListNode(nodesQueue.poll().val);
                p = p.next;
            }else{
                ListNode tmp = nodesQueue.poll();
                p.next = new ListNode(tmp.val);
                p = p.next;
                nodesQueue.add(tmp.next);
            }
        }
        return head.next;
    }

}
```