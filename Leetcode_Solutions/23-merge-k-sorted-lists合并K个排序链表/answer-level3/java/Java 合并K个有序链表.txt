### 解题思路
此处撰写解题思路

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
	// 时间复杂度O(K)
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists == null || lists.length == 0) {
			return null;
		}
        
		// 创建一个堆，并设置元素的排序方式
		PriorityQueue<ListNode> queue = new PriorityQueue(new Comparator<ListNode>() {
			public int compare(ListNode o1, ListNode o2) {
				return (o1.val - o2.val);
			}
		}); // 小顶堆
        
		// 遍历链表数组，然后将每个链表的每个节点都放入堆中
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                queue.add(lists[i]);
            }
        }
        
		ListNode newHead = new ListNode(0);
		ListNode p = newHead;
		// 从堆中不断取出元素，并将取出的元素串联起来
		while (!queue.isEmpty()) {
			ListNode tmp = queue.poll();
            p = p.next = tmp;
      
            if (tmp.next != null) {
                queue.add(tmp.next);
            }
		}
		p.next = null;
		return newHead.next;
	}
}
```