### 解题思路
- 首先要了解什么是链表，了解后，肯定能解出本题，也就是对应得节点进行求和来得到最终得链表，剩下的就是代码优化。
    - 搜索关键词：链表、linked list
    - 参考文章推荐：
        - [Computer science in JavaScript: Linked list](https://humanwhocodes.com/blog/2019/01/computer-science-in-javascript-linked-list/)
        - [维基(中文)](https://zh.wikipedia.org/wiki/%E9%93%BE%E8%A1%A8)
- 误区：
    - 这道题不能 342+465=807，然后把 807 变成链表，因为当链表足够长时得到的整型值会溢出。

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
var addTwoNumbers = function (l1, l2) {
    const node = new ListNode('head')
    let temp = node
    let sum
    let carry = 0 // 进位，英语就是 carry
    while (l1 || l2) {
        const n1 = l1 ? l1.val : 0
        const n2 = l2 ? l2.val : 0
        sum = n1 + n2 + carry
        temp.next = new ListNode(sum % 10)
        temp = temp.next
        /* 
            进位 普通做法：
            if (sum > 10) {
                carry= 1
            } else {
                carry= 0
            }
            优化： 
        */
        carry = parseInt(sum / 10)
        if (l1) {
            l1 = l1.next
        }
        if (l2) {
            l2 = l2.next
        }
    }
    if (carry > 0) {
        temp.next = new ListNode(carry)
    }
    return node.next
};
```