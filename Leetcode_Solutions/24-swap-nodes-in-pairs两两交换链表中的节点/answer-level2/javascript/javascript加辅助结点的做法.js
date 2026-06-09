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
var swapPairs = function(head) {
    //声明一个空结点
    let thead={
        val:null,
        next:head
    }
    //利用thead交换
    let c=thead
    while(c.next&&c.next.next){
        a=c.next
        b=c.next.next
        c.next=b
        a.next=b.next
        b.next=a
        c=c.next.next
    }
    return thead.next
};