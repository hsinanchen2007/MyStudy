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
 * while 往下走, pre记录着上一个节点，current 为游标，当current走到一个val不和上一个值相等的地方，表明current就是 pre 的下一个，依次赋值
 * 循环结束将 pre.next 置为 null，最后返回头节点
 */
var deleteDuplicates = function(head) {
    if (!head)
        return head;
    let currentVal = head.val,
        pre = head,
        current = head.next;
    while(current) {
        if (current.val === currentVal) {
            current = current.next;
        } else {
            pre.next = current;
            pre = pre.next;
            currentVal = current.val;
            current = current.next;
        }
    }
    pre.next = null;
    return head;
};
```