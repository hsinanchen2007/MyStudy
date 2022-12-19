```js
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
    const head = new ListNode(0)
    // push进位 head头结点(无数据的头结点)
    let push = 0, p = head
    // l1,l2或者push三者任意一个有值， 说明结果就没有结束，就有下一个新节点
    while(l1 || l2 || push){
        p = p.next = new ListNode()
        const sum = (l1 ? l1.val : 0) + (l2? l2.val : 0) + push
        p.val = sum > 9 ? sum % 10 : sum
        // push复位
        push = sum > 9 ? 1 : 0
        // l1 l2 顺延
        l1 = l1 ? l1.next : l1
        l2 = l2 ? l2.next : l2
    }
    return head.next?head.next:head
};
```