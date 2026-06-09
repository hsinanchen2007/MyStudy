### 解题思路

慢指针指向已确认的无重复元素的最后一项，快指针初始状态下指向慢指针的next，内循环后应该指向重复元素的最后一项。

若内循环退出后，快指针仍然指向next，说明此处没有重复元素，两个指针同时后移。

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
var deleteDuplicates = function(head) {
    let dummy = {next: head};
    let fast = head, slow = dummy;
    while(fast){
        while(fast.next && fast.next.val == fast.val){
            fast = fast.next;
        }
        if(slow.next != fast){
            slow.next = fast.next;
        }else{
            slow = slow.next;
        }
        fast = fast.next;
    }
    return dummy.next;
};
```