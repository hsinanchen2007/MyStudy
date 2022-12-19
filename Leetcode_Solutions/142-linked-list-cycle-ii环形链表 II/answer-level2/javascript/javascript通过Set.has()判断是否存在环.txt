### 解题思路
用一个set保存对应节点，若出现相同节点则表示有环，注意边界值
当空链表时直接返回null，当前或者下一个节点为空时也返回null

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
var detectCycle = function(head) {
    let nodeSet = new Set()
    let cur = head;
    let index = 0;
    while(cur){
        if(!cur||!cur.next) return null;
        if(nodeSet.has(cur)) return cur;
        nodeSet.add(cur);
        index++;
        cur = cur.next;
    }
    return null;
};
```