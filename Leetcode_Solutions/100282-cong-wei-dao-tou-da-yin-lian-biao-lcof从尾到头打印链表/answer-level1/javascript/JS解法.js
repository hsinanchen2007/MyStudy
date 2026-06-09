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
 * @return {number[]}
 */
var reversePrint = function(head) {
    let arr = []
    while(head){
        arr.push(head.val);
        head=head.next;
    }
    return arr.reverse()
};

// 时间复杂度：O(n)
// 空间复杂度：O(n)
```