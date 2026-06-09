### 解题思路
快慢指针法

### 代码
1. 快慢指针法
定义两个指针slow,fast  slow每次走一步，fast走两步
则当fast到达尾部时，slow正好走到中间
```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
		ListNode fast = head;
		ListNode slow = head;
		while (fast!=null && fast.next!=null) {
			fast = fast.next.next;
			slow = slow.next;
			
		}
		return slow;

}
}
        return slow
}
```
```python []
class Solution:
    def middleNode3(self, head: ListNode) -> ListNode:
        fast = slow = head
        while fast!= None:
            fast = fast.next.next
            slow = low.next
        return slow
```
2.单指针法
```java []
		int n=0;
		ListNode cur = head;
		while(cur!=null) {
			++n;
			cur=cur.next;
		}
		int k=0;
		ListNode cur2 = head;
		while (k<n/2) {
			++k;
			cur2 = cur2.next;
		}
		return cur2;	
	}
```
```python []
class Solution:
    def middleNode2(self, head: ListNode) -> ListNode:
        n = 0
        cur = head
        while cur:
            n+=1        # 记录n
            cur=cur.next  # 一次遍历
        k = 0
        cur = head
        while k<n//2:
            k += 1
            cur = cur.next
        return cur # 遍历到中间即返回
```
```ruby []
puts 'Hello world!'
```
