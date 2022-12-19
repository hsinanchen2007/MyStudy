### 解题思路
slow指针每次只移动一格，
quick指针每次移动两格，
当quick移动到null时，slow即为所求

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
    let slow=head;
    let quick=head.next;
    while(quick){
        slow=slow.next;
        quick=quick.next;
        if(quick)quick=quick.next;
    }

    return slow;



};
```