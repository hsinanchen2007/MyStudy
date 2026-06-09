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
 * @return {ListNode}
 */
var removeDuplicateNodes = function(head) {
    if(!head) return head;
    let obj = {};
    function clear(pi){
        if(!pi){
            return ;
        }
        if(obj[pi.val]){
            pi = clear(pi.next);
        }else{
            obj[pi.val] = true;
            pi.next = clear(pi.next);
        }
        return pi;
    }
    head = clear(head);
    return head;
};
```