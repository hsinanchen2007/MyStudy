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
    var head = new ListNode(0);
    var count = head;
    var flag = 0; // 表示进位
    while(l1 != null || l2 != null ){
        var v1 = l1 != null ? l1.val : 0;
        var v2 = l2 != null ? l2.val : 0;
        var sum = v1 + v2 + flag;
        var tmp = {};
        if(sum >= 10){
            tmp = new ListNode(sum - 10);
            flag = 1;
        }
        else{
            tmp = new ListNode(sum);
            flag = 0;
        }
        // console.log(tmp);
        count.next = tmp;
        count = count.next;
        l1 = l1 != null ? l1.next : null;
        l2 = l2 != null ? l2.next : null;
    }
    if(flag == 1){
        count.next = new ListNode(1);
    }
    return head.next;
};