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
var middleNode = function(head) {
    let node=head, fnode=node.next;
    while(fnode){
        node=node.next;
        if(!fnode.next)break;
        fnode=fnode.next.next;
    }
    return node;
};
```