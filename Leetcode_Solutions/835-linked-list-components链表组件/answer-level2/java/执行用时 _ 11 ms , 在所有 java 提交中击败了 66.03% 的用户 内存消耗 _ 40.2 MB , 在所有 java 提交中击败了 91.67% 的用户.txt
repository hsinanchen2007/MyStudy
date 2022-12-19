### 解题思路
这个题目主要是问题的理解，理解了题目其实并不难，其实就是找到链表中最长子链，如果长子链（组件）中包含短子链（组件）所对应的元素，就不算短子链（组件）个数了；
主要思路就是记录数组中哪些存在于链表中，然后循环链表，当判断链表的某个节点存在于数组中，此时就向下继续查找链表，看看是否还存在更长的子链，当遍历完链表，就找完了所有的子链（组件）

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
    public int numComponents(ListNode head, int[] G) {
 
		Map<Integer,Boolean> map = new HashMap<>();
		for(int i : G) {
			map.put(i, true);
		}
		int result = 0;
		ListNode p = head;
		while(p != null) {
			if(map.containsKey(p.val) && map.get(p.val)) {
				//ListNode q = p.next;
				while(p.next != null && map.containsKey(p.next.val) && map.get(p.next.val)) {//判断还有没有更长的
					p = p.next;
				}
				result++;
			}
			p = p.next;
			
		}
		return result;
    }
}
```