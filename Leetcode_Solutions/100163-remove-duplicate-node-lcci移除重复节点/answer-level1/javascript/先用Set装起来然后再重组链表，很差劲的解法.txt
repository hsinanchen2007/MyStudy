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
var removeDuplicateNodes = function(head) {
    if(!head)return null;
    const set = new Set();
    let node = head;
    while(node){
        set.add(node.val);
        node=node.next;
    }
    const arr = [...set].map(e=>new ListNode(e));
    for(let i=0; i<arr.length-1; i++){
        arr[i].next=arr[i+1];
    }
    return arr[0];
};
```