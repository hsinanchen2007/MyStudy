
#### 链表 
+ [戳看链表各种操作大全](https://github.com/Alex660/Algorithms-and-data-structures/blob/master/algo/%E9%93%BE%E8%A1%A8_linkedList.md)
#### 解法：指针遍历
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
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
    let cur = head
    while(cur && cur.next) {
        if(cur.next.val === cur.val) {
            cur.next = cur.next.next
        }
        else{cur = cur.next}
    }
    return head
};
```