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
var reverseList = function(head) {
    // if(!head){
    //     return head
    // }
    let pre = head
    let cur = null
    while(pre){
        let tmp = pre.next
        pre.next = cur
        cur = pre
        pre = tmp
    }

    return cur
};
```