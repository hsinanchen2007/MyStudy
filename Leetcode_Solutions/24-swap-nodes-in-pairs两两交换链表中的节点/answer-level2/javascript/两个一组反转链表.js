### 解题思路
在链表头部增加一个pre节点，缓存pre.next-node1,pre.next.next-node2,
两两反转就是将node1指向node2.next，node2指向node1，再讲pre指向node1，以此循环

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
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(!(head && head.next)) {
        return head
    }

    let p = list =  new ListNode(null)
    p.next = head
    let node1 = p.next
    let node2 = p.next.next

    while (p.next && p.next.next) {
        node1.next = node2.next
        node2.next = node1
        p.next = node2
        p = node1
        node1 = p.next
        node2 = p.next && p.next.next ? p.next.next : null
    }
    console.log(list)
    return list.next
};
```