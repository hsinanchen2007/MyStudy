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
var deleteDuplicates = function(head) {
    let current = head;
    let temp = head;
    while(current && current.next){
        while(temp && temp.next && temp.val === temp.next.val){
            temp = temp.next;
        }
        temp = temp.next;
        current.next = temp;
        current = temp;
    }
    return head;
};
```