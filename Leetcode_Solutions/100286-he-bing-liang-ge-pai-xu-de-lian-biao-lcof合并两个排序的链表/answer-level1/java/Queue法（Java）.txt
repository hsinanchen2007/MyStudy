### 解题思路
声明：可以一个队列也可以两个队列，两个队列速度更快，内存消耗更高

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null) return null;
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        Queue<ListNode> queue = new LinkedList<>();
        //添加有序结点到队列中
        while(l1 != null || l2 != null){
            //判断是否单个到终点
            if(l1 == null && l2 != null){
                queue.add(l2);
                l2 = l2.next;
                continue;
            }else if(l2 == null && l1 != null){
                queue.add(l1);
                l1 = l1.next;
                continue;
            }
            //将两个链表有序放入队列中
            if(l1.val <= l2.val){
                queue.add(l1);
                l1 = l1.next;
            }else{
                queue.add(l2);
                l2 = l2.next;
            }
        }
        //取出链表
        ListNode resNode = queue.poll();
        ListNode temp = resNode;
        while(!queue.isEmpty()){
            temp.next = queue.poll();
            temp = temp.next;
        }
        return resNode;
    }
}
```