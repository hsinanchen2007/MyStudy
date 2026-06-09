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
    let curr = head;
    if(head ===  null) return null;
    while(curr !== null && curr.next !== null){
        if(curr.val === curr.next.val){
           curr.next = curr.next.next;
        }else{
           curr = curr.next
         }
    }
    return head;
};