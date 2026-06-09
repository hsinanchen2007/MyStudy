### 解题思路
快慢指针，找到中间的位置，反转后半段链表

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
var isPalindrome = function(head) {
    let slow=head
    let fast=head
    let h=head
    if(head==null || head.next==null) return true
    while(fast && fast.next){
        slow=slow.next
        fast=fast.next.next
    }

    let head2=slow
    if(fast!=null) head2=head2.next

    let p1=head2
    let p2=null
    while(p1){
        let p3=p1.next
        p1.next=p2
        p2=p1
        p1=p3
    }


    while(p2){
        if(p2.val!=h.val) return false
        p2=p2.next
        h=h.next
    }
    
    return true
};
```