### 解题思路
此处撰写解题思路
遍历链表时候开始计数，当计算器能被k整除时候反转当前节点之前的链表，并保存新的头尾，最终拼接首尾节点。
### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseKGroup(ListNode head, int k) {
      	if ( k == 1 ) return head;
			var array = new List<ListNode[]>();
			var newhead = head;
			var current = head;
			var index = 0;
			while ( current != null ) {
				index++;
				if ( index % k == 0 ) {
					var next = current.next;
					current.next = null;
					var r = Reversal(newhead);
					array.Add(new ListNode[] { r, newhead });
					newhead = next;
					current = next;
					continue;
				}
				current = current.next;
			}
			if ( array.Count == 1 ) {
				array[0][1].next = newhead;
				return array[0][0];
			}
				for ( var i = 1; i < array.Count; i++ ) {
				array[i - 1][1].next = array[i][0];
			}
			if ( newhead != null ) {
				array[array.Count - 1][1].next = newhead;
			}
			return array[0][0];
    }
    public ListNode Reversal(ListNode node) {
			if ( node == null || node.next == null ) {
				return node;
			}
			var temp = node.next;
			var newhead = Reversal(node.next);
			temp.next = node;
			node.next = null;
			return newhead;
	}
}
```