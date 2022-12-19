用容器存储遍历到的节点，遍历到相同的则退出循环即找到相遇点
```
public class Solution {
    public ListNode detectCycle(ListNode head) {
                		if(head == null||head.next==null)
		return null;
	List<ListNode> hash= new ArrayList<>();
	ListNode cur = head;
	while(!hash.contains(cur)) {
		if(cur.next==null)
			return null;
		hash.add(cur);
		cur = cur.next;
	}
		return cur;
    }
}
```
