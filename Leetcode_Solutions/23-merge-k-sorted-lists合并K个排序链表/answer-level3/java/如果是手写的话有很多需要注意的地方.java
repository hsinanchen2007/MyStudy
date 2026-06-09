
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 import java.util.*;
class Solution {
    public  ListNode mergeKLists(ListNode[] lists) {
        if(lists==null || lists.length==0)
            return null;
        if(lists.length==1)
            return lists[0];
//        Queue<ListNode> queue=new PriorityQueue<>(new Comparator<ListNode>() {
//            @Override
//            public int compare(ListNode o1, ListNode o2) {
//                return o1.val-o2.val;
//            }
//        });

        //1.手写需要注意别写错了new PriorityQueue<>(),有尖括号和圆括号
        // 2.默认是小根堆？是的，如果是Interger、String等类型，不需要传入Comparator比较器 但是这里是ListNode，需要自定义比较器，否则会报错
        //小根堆：o1.val-o2.val
        // 3. lambda表达式怎么写？ (node1,node2)->(node1.val-node2.val)
        Queue<ListNode> queue =new PriorityQueue<>((node1,node2)->(node1.val-node2.val));

        for(int i=0;i<lists.length;i++){
            if (lists[i]!=null)
            queue.offer(lists[i]);
        }
        ListNode head=new ListNode(0),ans=head;
        while(!queue.isEmpty()){
            ListNode nextNode=queue.poll();
            ans.next=nextNode;
            ans=nextNode;
            if(nextNode.next!=null)
                queue.offer(nextNode.next);
        }
        return head.next;
    }
}
```