将链表转换为数组处理后再转为链表
```
// time: 60ms(90.47%) memory: 33.9(11.69%)
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
    let arr = [], _arr = [];
    let res = new ListNode(null);

    function transform(l, arr) {
        while(l) {
            arr.push(l.val);
            l = l.next;
        }
    }

    transform(head, arr);
    if (arr.length <= 1) return head;
    for (let i = 0; i < arr.length; i += 2) {
        arr[i + 1] !== undefined ? _arr.push(arr[i + 1], arr[i]) : _arr.push(arr[i]);
    }

    for (let i = _arr.length - 1; i >= 0; i--) {
        let temp = new ListNode(null);
        res.val = _arr[i];
        temp.next = res;
        res = temp;
    }

    return res.next;
};
```