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
var middleNode1 = function(head) {
    const nodes=[]
    let cur=head
    do{
        nodes.push(cur)
        cur=cur.next
    }while(cur)
    const i=nodes.length%2===0 ? Math.ceil(nodes.length/2) : Math.ceil(nodes.length/2)-1
    return nodes[i]
};
// 快慢指针
var middleNode = function (head) {
    let slow = head;
    let fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
};
```