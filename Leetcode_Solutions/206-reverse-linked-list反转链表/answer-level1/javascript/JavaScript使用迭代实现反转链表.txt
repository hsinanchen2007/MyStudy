每日一题，打卡 -- Day2

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
    if(!head || !head.next) return head;

    //迭代
    let prev = null;
    let current = head;

    while(current){
        const nextNode = current.next;
        current.next = prev;
        prev = current;

        current = nextNode;
    }

    return prev;
};
```
