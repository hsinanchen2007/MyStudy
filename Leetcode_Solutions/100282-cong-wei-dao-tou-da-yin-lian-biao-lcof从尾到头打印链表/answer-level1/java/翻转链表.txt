### 解题思路
本题难点在于不知道链表长度，因此不好创建数组
另一个就是翻转链表了
那我们就在翻转链表的时候统计链表长度就行了
链表逆向输出，那就翻转链表，然后循环存入数组；

**翻转思路：**
    创建一个空链表node
    将head头节点拿过来当作node的头节点
    而后跟新head跟node（head = 新head && node = 新node）
    方便下次循环拿的时候用
最后将翻转后的链表node循环存入数组中

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
    public int[] reversePrint(ListNode head) {

	ListNode node = null;
	int size = 0;
	while(head!=null) {
		ListNode temp = head.next;
		head.next = node;
		node = head;
		head = temp;
		size++;
	}
	int[] nums = new int[size];
	for(int i=0;i<size;i++) {
		nums[i] = node.val;
		node = node.next;
	}
	return nums;
    }
}
```