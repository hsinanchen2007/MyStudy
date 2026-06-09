### 解题思路
迭代法

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
var mergeTwoLists = function(l1, l2) {
    if(l1 === null) { // 若l1为空链表，由于l2已经为有序链表（或为空链表），直接返回即可
        return l2;
    } else if(l2 === null) { // 同理
        return l1;
    } else {
        const preNode = new ListNode(-1); // 这里实际上设任意数值均可，不一定要设为-1
        let temp = preNode; // 设置一个节点来进行迭代
        while(l1 !== null || l2 !== null) { // 有一个不为空链表时进行循环
            if(l1 === null) {
                temp.next = new ListNode(l2.val);
                temp = temp.next;
                l2 = l2.next;
            } else if(l2 === null) {
                temp.next = new ListNode(l1.val);
                temp = temp.next;
                l1 = l1.next;
            } else {
                if(l1.val <= l2.val) {
                    temp.next = new ListNode(l1.val);
                    temp = temp.next;
                    l1 = l1.next;
                } else {
                    temp.next = new ListNode(l2.val);
                    temp = temp.next;
                    l2 = l2.next;
                }
            }
        }
        return preNode.next;
    }
    

};
```