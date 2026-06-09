### 解题思路
思路和官方一样，做了点改动，同时遍历两个链表的指针，val相加得到一个新的sum，取模当成新节点的val，大于10时进一位到下一个节点，需要考虑链表长度不一致的情况；
例如：
[2,4,5,7,8,5,6,8,9,6]
[3,5,6]

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
* }  
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var dummy = new ListNode(0);
    var pre = dummy;
    var p = l1;
    var q = l2;
    var carray = 0, sum = 0;
    while(p !== null || q !== null) {
        // 防止链表长度不一致导致的浪费
        if (p !== null && q === null && carray === 0) {
            pre.next = p;
            carray = 0
            break;
        }
        if (q !== null && p === null && carray === 0) {
            pre.next = q;
            carray = 0;
            break;
        }
        var x = p !== null ? p.val : 0;
        var y = q !== null ? q.val : 0;
        sum = carray + x + y;
        carray = sum > 9 ? 1 : 0;
        var nextNode = new ListNode(sum % 10);
        pre.next = nextNode;
        pre = pre.next;
        if (p !== null) {
            p = p.next;
        }
        if (q !== null) {
            q = q.next;
        }
        
    }
    if (carray > 0) {
        pre.next = new ListNode(carray);
    }
    return dummy.next;
};
```