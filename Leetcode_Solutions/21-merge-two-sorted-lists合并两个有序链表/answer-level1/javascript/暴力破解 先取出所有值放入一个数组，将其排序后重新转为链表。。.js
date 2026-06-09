```
// time: 92ms(25.86%) memory: 36.6MB(5.81%)
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
var mergeTwoLists = function(l1, l2) {
    function transform(l, arr) {
        while(l) {
            arr.push(l.val);
            l = l.next;
        }
    }

    let arr = [];
    let res = new ListNode(null);

    transform(l1, arr);
    transform(l2, arr);
    arr.sort((a, b) => a - b);

    for (let i = arr.length - 1; i >= 0; i--) {
        let temp = new ListNode(null);
        res.val = arr[i];
        temp.next = res;
        res = temp;
    }

    return res.next;
};
```