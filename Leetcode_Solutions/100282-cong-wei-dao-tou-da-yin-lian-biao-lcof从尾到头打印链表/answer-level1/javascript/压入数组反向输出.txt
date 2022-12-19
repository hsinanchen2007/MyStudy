### 解题思路
将链表的值顺序压入数组，再反向输出

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrint = function(head) {
    var arr=new Array();
    while(head){
        arr.push(head.val);
        head=head.next;
    }
    return arr.reverse();
};
```