### 解题思路
此处利用快指针走到头，慢指针走到中间，然后慢指针的起点就是链表的下半段
慢指针走的时候利用链表的翻转，保存另一个链表，然后比较两个链表的值
注意奇数偶数

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
    if(head == null || head.next == null) {return true}
    let slow = head
    let fast = head
    let temp1 = null ,temp2 = null
    while(fast !=null && fast.next !=null){
        temp1 = slow
        slow = slow.next
        fast = fast.next.next

        temp1.next  = temp2
        temp2 = temp1
    }
    if(fast){
        slow = slow.next
    }

    while(slow){
        if(slow.val != temp2.val){return false}
        slow = slow.next 
        temp2 = temp2.next
    }
    return true


};
```