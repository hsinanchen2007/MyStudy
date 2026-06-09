### 解题思路
1. 利用寻找链表中间节点的方法，得到中点，在此过程中反转前一半的链表
2. 然后前后进行比较
3. 注意，奇数个和偶数个链表元素是不一样的

### 代码
```
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
  if (!head || !head.next) {
    return true
  }
  let slow = head
  let quick = head
  let temp1 = null    // 存储上一个slow值
  let temp2 = null    // 存储下一个slow值
 while(quick && quick.next) {   // 反转中点以前的值
   quick = quick.next.next
   temp2 = slow.next
   slow.next = temp1
   temp1 = slow
   slow = temp2
 }
 if (quick) {   // 对于奇数和偶数链表，quick的值不一样
   slow = slow.next
 }

 while(temp1 && slow && temp1.val === slow.val) {
   temp1 = temp1.next
   slow = slow.next
 }

 if (!temp1 && !slow) {
   return true
 } else {
   return false
 }
};
```
