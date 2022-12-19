### 解题思路
构造一个小顶堆，小顶堆中的元素是一个int[]数组。
int[]数组的构成为 ListNode.val和index 
index用来标识该val是lists中的哪条链表

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
        //小顶堆
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0]-o2[0];
            }
        });
        int i = 0;
        for (ListNode list : lists) {
            if (list != null)
                pq.add(new int[]{list.val,i});
            i++;
        }
        ListNode head = new ListNode(-1);
        ListNode result = head;
        while (pq.size() != 0){
            int[] remove = pq.remove();
            head.next = new ListNode(remove[0]);
            head = head.next;
            int index = remove[1];
            //当前链表未空
            if(lists[index].next != null){
                pq.add(new int[]{lists[index].next.val,index});
                lists[index] = lists[index].next;
            }
        }
        return result.next;
    }
}
```