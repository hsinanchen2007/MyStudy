### 解题思路
总感觉题目有点误导人，虽说是逆序相加的，但后面还是会反转过来，其实就是两个链表的头指针往后每个节点的值相加，有进位则加到下一次两个节点之和上。不过加到最后有两个地方需要注意下：1，进位值为0，但有一个指针未移到末尾null；2，指针都移到末尾null了，但进位值为1。想清楚这两点写起来就很快了。

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
 	let p1 = l1;
	let p2 = l2;
	let p3;
	const head = new ListNode(0);
	let sumNode = head;
	let carry = 0;
	do {
		let sum = p1.val + p2.val + carry;
		sumNode.next = new ListNode(sum % 10);
		carry = sum >= 10 ? 1 : 0;
		sumNode = sumNode.next;

		p1 = p1.next;
		p2 = p2.next;
		if (p1 === null) {
			p3 = p2;
		} else if (p2 === null) {
			p3 = p1;
		}
	} while (p1 != null && p2 != null);

    for (; p3 !== null; p3 = p3.next) {
        if (carry > 0) {
            let sum = p3.val + carry;
            carry = sum >= 10 ? 1 : 0;
            sumNode.next = new ListNode(sum % 10);
            sumNode = sumNode.next;
        } else {
            sumNode.next = new ListNode(sum % 10);
            sumNode = sumNode.next;
        }
    }
	if (carry > 0) {
        sumNode.next = new ListNode(carry);
	}
	return head.next;
};

```