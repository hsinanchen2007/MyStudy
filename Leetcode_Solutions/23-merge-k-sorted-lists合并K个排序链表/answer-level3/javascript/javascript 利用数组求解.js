### 解题思路
使用数组作为辅助

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
    const len = lists.length
    if (len === 0) {
        return null
    }
    const temp = []
    for (let i = 0; i < len; i ++) {
        const list = lists[i]
        let cur = list
        while(cur) {
            temp.push(cur.val)
            cur = cur.next
        }
    }
    const tLen = temp.length
    if (tLen === 0) {
        return null
    }
    temp.sort((a, b) => a - b)
    const head = new ListNode(temp[0])
    let cur = head
    for (let i = 1; i < tLen; i ++) {
        const node = new ListNode(temp[i])
        cur.next = node
        cur = cur.next
    }
    return head
};
```