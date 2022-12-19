### 解题思路
一个链表设置两个指针，一个快指针一个慢指针。快指针每次走2步，慢指针每次走1步。
如果链表有环的情况下那么快指针就不会指向null，也就是说如果快指针指向null，即证明链表没环。
由于快指针每次走2步，若链表存在环，则快指针必定将在环的某一步追上慢指针实现套圈，即快慢指针指向同一
结点，即返回true。
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
 * @return {boolean}
 */
var hasCycle = function(head) {
    let fastHead = head;
    let slowHead = head;
    while(fastHead){
        fastHead = fastHead.next;
        slowHead = slowHead.next;
        if(!fastHead) return false;
        fastHead = fastHead.next;
        if(fastHead === slowHead) return true;
    }
    return false;
};
```