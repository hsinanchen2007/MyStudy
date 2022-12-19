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
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    let arr = [];
    for(let i = 0; i < lists.length; i++) {
        while(lists[i]) {
            arr.push(lists[i].val);
            lists[i] = lists[i].next;
        }
    }
    arr.sort((a,b) => a-b);
    let head = new ListNode(0);
    let current = head;
    for(let i = 0; i < arr.length; i++) {
        current.next = new ListNode(arr[i]);
        current = current.next;
    }
    return head.next;
};
```