### 解题思路
此处撰写解题思路

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
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
    if(head.val == val){
        return head.next;
    }
    var str = "head";
    var count = head;
    while(count.next != null){
        if(count.next.val == val){
            str = str + ".next = " + str + ".next.next";
            break;
        }
        str += ".next";
        count = count.next;
    }
    eval(str);
    return head;
};
```