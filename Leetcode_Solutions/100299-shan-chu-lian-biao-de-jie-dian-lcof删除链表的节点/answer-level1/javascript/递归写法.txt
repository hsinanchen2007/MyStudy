### 解题思路
1.改变val值的head.next指向

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
        return head.next
    }
    /**
     * 假设【1，2，3】，目标值是2
     * 当前head是1.
     * 本来head.next是2,但是调用deletenode函数的时候刚刚好2==2,把2（head）的下一个值3的指针返回回去
     * 所以head.next = 3
     * 1->3
     * 
    */
    head.next = deleteNode(head.next,val);
    return head
};
```