### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
                var pre = new ListNode(-1);
				pre.next = head;
				
				var node = pre;
				while(node.next){//遍历链表
					if(node.next.val===val){//判断值与val是否相等
						node.next = node.next.next;
						break;
					}
					node = node.next;
				}
				return pre.next;
};

```