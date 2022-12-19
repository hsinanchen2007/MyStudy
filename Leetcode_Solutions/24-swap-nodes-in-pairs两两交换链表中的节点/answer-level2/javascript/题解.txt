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
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if(head == null || head.next == null) { // 如果为h空，返回头节点
        return head;
    }
    let p = dummyHead = new ListNode(); // 声明两个空节点。
    p.next = head; // p的next指向head
    let node1, node2;
    while((node1 = p.next) && (node2 = p.next.next)) { // node1记录第一个节点。node2记录第二个节点
        node1.next = node2.next;  // node1的节点指向node2的下一个节点
        node2.next = node1; // node2的下一个节点指向node1
        p.next = node2; // 头节点dunmmyHead.next指向node1
        p = node1; // 交换p节点到下一组的上一个节点
    }
    return dummyHead.next;
};
```