### 解题思路
简单粗暴野蛮不加思考的解 只求结果

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
        if (l1 == null && l2 == null) {
	    return null;
	}
        ArrayList<Integer> list = new ArrayList<Integer>();
	while (l1 != null) {
	    list.add(l1.val);
	    l1 = l1.next;
	}
	while (l2 != null) {
	    list.add(l2.val);
	    l2 = l2.next;
	}
	list.sort(new Comparator<Integer>() {
	    @Override
	    public int compare(Integer o1, Integer o2) {
		return o1 - o2;
	    }
	});
	ListNode re = new ListNode(list.get(0));
	ListNode t = re;
	for (int i = 1; i < list.size(); i++) {
	    t.next = new ListNode(list.get(i));
	    t = t.next;
	}
	return re;
    }
}
```