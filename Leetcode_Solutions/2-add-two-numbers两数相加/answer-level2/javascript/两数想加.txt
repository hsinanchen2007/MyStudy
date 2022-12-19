/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let newLHead = null
    let newL = null
    let rest = 0
    let p1 = l1
    let p2 = l2
    while(p1 || p2 || rest ){
        let val = 0
        if(p1){
            val = p1.val + val
            p1 = p1.next
        }
        if(p2){
            val =p2.val + val
            p2 = p2.next
        }
        val = val + rest
        if(!newLHead){
            newLHead = new ListNode(val % 10)
            newL = newLHead
        }else{
            newL.next  = new ListNode(val % 10)
            newL = newL.next
        }
        rest = val >= 10 ? 1 : 0
    }
    return newLHead
};