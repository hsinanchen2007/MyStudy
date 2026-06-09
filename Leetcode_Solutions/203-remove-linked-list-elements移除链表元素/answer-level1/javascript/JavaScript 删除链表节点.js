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
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    let Vnode = new ListNode(-99);
    Vnode.next = head;
    let p = Vnode;
    while(p && p.next){
        if(p.next.val == val){
            p.next = p.next.next;
        }else{
            p = p.next;
        }
        
    }
    return Vnode.next;
};
```