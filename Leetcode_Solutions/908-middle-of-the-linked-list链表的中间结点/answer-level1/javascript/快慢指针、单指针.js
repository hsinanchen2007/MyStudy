### 解题思路
方法一、快慢指针

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
var middleNode = function(head) {
    var fast=slow=head;
    while(fast!=null && fast.next!=null){
        slow=slow.next;
        fast=fast.next.next;
    }
    return slow;
};
```
方法二、单指针
```
var middleNode = function(head) {
    var n=0;
    var p=head;
    while(p!=null){
        n++;
        p=p.next;
    }
    var i=0;
    p=head;
    while(i<Math.floor(n/2)){
        ++i;
        p=p.next;
    }
    return p;
};
```

