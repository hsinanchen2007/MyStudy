遍历取出所有的值放入数组，排序后重新将其生成为链表
```
// time: 104ms(80.94%) memory: 38.9MB(51.88%)
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    function transform(l, arr) {
        while(l) {
            arr.push(l.val);
            l = l.next;
        }
    }

    let arr = [];
    let res = new ListNode(null);

    lists.map(item => transform(item, arr));
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