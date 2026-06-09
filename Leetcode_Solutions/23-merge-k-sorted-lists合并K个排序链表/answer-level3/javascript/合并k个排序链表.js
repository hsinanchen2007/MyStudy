先把所有的val放在数组里，进行排序，然后再构造一个链表

```javascript
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
    const len = lists.length;
    if(len === 0) return null;
    let temp = [];
    for(let i = 0; i < lists.length; i++) {
        let curList = lists[i];
        let cur = curList;
        while(cur) {
            temp.push(cur.val);
            cur = cur.next;
        }
    }
    if(!temp.length) return null;
    temp.sort((a,b) => a - b);
    let ans = new ListNode(temp[0]);
    let cur = ans;
    for(let i = 1; i < temp.length; i++) {
        let node = new ListNode(temp[i]);
        cur.next = node;
        cur = cur.next;
    }
    return ans;
};
```
遍历所有节点时间复杂度O(n),申请数组空间，空间复杂度O(n)
对数组进行排序，JS中sort算法喂快排，时间复杂度为O(logn)
数组转化为链表，时间复杂度为O(n)，空间复杂度为O(n)