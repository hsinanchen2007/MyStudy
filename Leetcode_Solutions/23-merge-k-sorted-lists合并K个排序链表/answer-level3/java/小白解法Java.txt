### 解题思路
关注知乎一起学习讨论
https://www.zhihu.com/people/god-jiang

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
        if(lists==null || lists.length==0){
            return null;
        }
        PriorityQueue<ListNode> queue = new PriorityQueue<>(lists.length,new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1,ListNode o2){
                return o1.val-o2.val;
            }
        });
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        for(ListNode node:lists){
            if(node!=null){
                queue.offer(node);
            }
        }
        while(!queue.isEmpty()){
            p.next=queue.poll();
            p=p.next;
            if(p.next!=null){
                queue.offer(p.next);
            }
        }
        return dummy.next;
    }
}
```