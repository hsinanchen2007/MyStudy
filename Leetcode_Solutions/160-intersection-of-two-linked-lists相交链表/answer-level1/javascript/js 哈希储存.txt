```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    const map = new Map()
    let p = headA
    while(p){
        map.set(p, true)
        p = p.next
    }
    p = headB
    while(p){
        if(map.get(p)) return p
        p = p.next
    }
    return null
};
```
