### 解题思路
1. 将每一个链表的首元素添加到优先队列中，key为Node的值
2. poll()出值，将该链表的下一个元素添加到优先队列中

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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(0);
        ListNode p = new ListNode(0);
        ListNode q = head;
        Comparator<ListNode> OrderIsdn =  new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                if(o1.val>o2.val){
                    return 1;
                }else{
                    return -1;
                }
            }
        };

        Queue<ListNode> priorityQueue =  new PriorityQueue<ListNode>(OrderIsdn);
        for(ListNode list:lists){
            if(list!=null) {
                priorityQueue.add(list);
            }
        }

        while(priorityQueue.isEmpty()==false){
            p=priorityQueue.poll();
            int val=p.val;
            if(p.next!=null){
                p=p.next;
                priorityQueue.add(p);
            }
            q.next= new ListNode(val);
            q=q.next;
            
        }


        return head.next;
    }
}

```