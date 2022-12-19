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
var deleteNode2 = function(head, val) { // 非递归算法

    if (!head) return null

    let dummyHead = {} 
    dummyHead.next = head

    let prev = dummyHead, cur = head
    while (cur) {
        if (cur.val === val)
            prev.next = cur.next;
        else
            prev = cur
        cur = cur.next
    }

    return dummyHead.next
};

const deleteNode = (head, val) => { // 递归算法
    
    if (!head) return null

    head.next = deleteNode(head.next, val)
    return head.val === val ? head.next : head
}
```