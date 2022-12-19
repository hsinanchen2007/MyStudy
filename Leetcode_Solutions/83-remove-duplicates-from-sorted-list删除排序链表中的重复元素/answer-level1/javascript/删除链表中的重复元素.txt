### 解题思路
主要是对链表指针的理解
### 复杂度分析
注意这是一个有序链表。
时间复杂度：O(n)因为列表中的每个结点都检查一次以确定它是否重复，所以总运行时间为 O(n)，其中 n 是列表中的结点数。
空间复杂度：O(1)，没有使用额外的空间。

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
   var current = head;
   while(current && current.next) {
       if(current.val === current.next.val) {
           current.next = current.next.next; // head是头指针, 是不会发生变动的，current是临时指针，对链表的操作就是操作current
       } else {
           current =  current.next;
       }
   }
   return head;
};
```