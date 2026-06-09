### 解题思路

定义一个前置节点prev， 三个节点来回互换
prev.next = first.next
first.next = second.next
second.next = first


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
// 使用prev节点记录前一个节点
var swapPairs = function(head) {
    if(head === null) return null
    if(head.next === null) return head


    let first,second
    let prev = new ListNode(-1)
    const newHead = head.next

    while(head && head.next){
        first = head
        second = head.next

        prev.next = first.next
        first.next = second.next
        second.next = first

        head = first.next
        prev = first
    }
    
    return newHead
};
```