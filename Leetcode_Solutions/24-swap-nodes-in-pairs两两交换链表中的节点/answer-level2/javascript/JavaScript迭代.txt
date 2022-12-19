```
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
    var pre  = new ListNode(-99);
    if(!head) return null; //空值判断
    var result = head.next? head.next:head;
    pre.next = head;
    while(pre.next&&pre.next.next){
       let left = pre.next;
       let right = pre.next.next;
        if(right.next){
            //非结尾情况
           pre.next = right;
           left.next = right.next;
           right.next = left;
           pre = left;
        }else {
            //结尾情况
            pre.next = right;
            right.next = left;
            left.next = null;
            pre = left;
        }
    }
    return result;
};
```
