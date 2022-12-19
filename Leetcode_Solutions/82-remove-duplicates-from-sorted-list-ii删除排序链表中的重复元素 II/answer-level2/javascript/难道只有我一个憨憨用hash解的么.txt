### 解题思路


第一遍用的hash，后来看了大家的快慢节点，顿觉我是个憨憨

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
// 快慢节点，哑节点dummy
var deleteDuplicates = function(head) {
    if(!head || !head.next) return head
    let dummy = new ListNode(0)
    dummy.next = head
    let slow = dummy
    let fast = dummy.next
    while(fast){
        while(fast.next && fast.val === fast.next.val) fast = fast.next
        if(slow.next === fast){
            slow = slow.next
        }else{
            slow.next = fast.next
        }
        fast = fast.next
    }
    return dummy.next
}
// hash
// var deleteDuplicates = function(head) {
//     let hash = {}
//     let curr = head
//     while(curr){
//         if(!hash[curr.val]){
//             hash[curr.val] = 1
//         }else{
//             hash[curr.val]++
//         }
//         curr = curr.next
//     }
    
//     let newHead = null
//     let newCurr = null
//     while(head){
//         if(!newHead){
//             if(hash[head.val] === 1){
//                 newHead = head
//                 newCurr = newHead
//             }
//         }else{
//             if(hash[head.val] === 1){
//                 newCurr.next = head
//                 newCurr = head
//             }
//         }
//         head = head.next
//         if(newCurr) newCurr.next = null
//     }
//     return newHead
// };
```