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
function ListNode(val) {
     this.val = val;
     this.next = null;
}
var mergeKLists = function(lists) {
    const result = new ListNode(null);
    let tmp = result
    for (let i = 0; i < lists.length; i++) {
        let l1 = tmp.next
        let l2 = lists[i]
        tmp.next = mergeTwoLists(l1, l2)
    }
    return result.next
};

function mergeTwoLists(l1, l2) {
    const result = new ListNode(null);
    let tmp = result;
    while(l1 && l2) {
        if (l1.val > l2.val) {
            tmp.next = l2;
            l2 = l2.next;
        } else {
            tmp.next = l1;
            l1 = l1.next;
        }
        tmp = tmp.next
    }
    tmp.next = l1 ? l1 : l2
    return result.next;
}
```