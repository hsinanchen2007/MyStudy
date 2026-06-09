### 解题思路
优先队列保存所有ListNode，按照val值排序

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    class nodeComparator implements Comparator<ListNode>{
        @Override
        public int compare(ListNode n1,ListNode n2){
            return n1.val - n2.val ;   
        }                               //          Integer a = n1.val , b = n2.val ;
                                        //          return a.compareTo(b) ;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0 || lists == null) return null ;
        PriorityQueue<ListNode> pqueue = new PriorityQueue<>(new nodeComparator()) ;
        for(int i = 0 ; i < lists.length ; i++){
            while(lists[i] != null){
                pqueue.add(lists[i]) ;
                lists[i] = lists[i].next ;
            }
        }
        ListNode node = new ListNode(0) ;
        node.next = null ;
        ListNode removeNode = node ;
        while(!pqueue.isEmpty()){
            ListNode temp = pqueue.poll() ;
            temp.next = null ;
            removeNode.next = temp ;
            removeNode = removeNode.next ;
        }
        return node.next ;   
    }
}
```