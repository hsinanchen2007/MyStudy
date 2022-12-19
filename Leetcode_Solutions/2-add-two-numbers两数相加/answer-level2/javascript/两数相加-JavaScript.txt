JS题解，和Java类似，但是注意JS是弱类型，在遇到小数会转为float。因此需要Math.float()方法向下取整数
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
    var result = new ListNode(0);
    var acc = result;
    var  more = 0;
    while(l1 != null || l2 != null){
        var x = (l1 != null ) ? l1.val : 0;
        var y = (l2 != null ) ? l2.val : 0;
        var sum = more + x + y
        more = sum/10
        more = Math.floor(more)
        acc.next = new ListNode(sum % 10)
        acc = acc.next
        if(l1 != null) l1 = l1.next
        if(l2 != null) l2 = l2.next
    }
    if(more >= 1 ){
        acc.next = new ListNode(more)
    }
    return result.next
};
