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
 * @param {number} carry 进位
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2, carry = 0) {
    // 将两个链表同位相加，还要加上次同位相加的进位
    let val = l1.val + l2.val + carry
    if (val >= 10) {
        // 大于 10， 进一位
        val = val % 10
        carry = 1
    } else {
        // 小于 10 不用进位
        carry = 0
    }

    // 只要有下一位或进位，next 是下一位和进位的和，否则 next 就是 null
    return {
        val: val,
        next:
            l1.next || l2.next || carry
                ? addTwoNumbers(
                      l1.next || { val: 0, next: null },
                      l2.next || { val: 0, next: null },
                      carry
                  )
                : null
    }
}

```
