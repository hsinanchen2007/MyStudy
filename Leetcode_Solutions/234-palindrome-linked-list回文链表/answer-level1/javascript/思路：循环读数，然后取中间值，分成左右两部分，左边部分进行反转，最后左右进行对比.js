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
 * @return {boolean}
 */
var isPalindrome = function(head) {
	let arr = []
	while (head) {
		arr.push(head.val)
		head = head.next
	}

	let arr_left = []
	let arr_right = []
	let mid = Math.floor(arr.length / 2)
	if (arr.length % 2 === 1) {
		arr_left = arr.slice(0, mid + 1)
	} else {
		arr_left = arr.slice(0, mid)
	}
	arr_right = arr.slice(mid)

	let _re_arr_left = arr_left.reverse()

	for (let i = 0; i < _re_arr_left.length; i++) {
		if (_re_arr_left[i] !== arr_right[i]) {
			return false
		}
	}
	return true
};
```