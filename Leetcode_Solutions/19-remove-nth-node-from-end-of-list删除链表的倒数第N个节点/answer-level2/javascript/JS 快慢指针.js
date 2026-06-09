### 解题思路
因为是找倒数第N个元素
先让快指针走N步
然后慢指针也开始走，当快指针走到最后的时候，他和慢指针的差距还是N，所以这时候将慢指针跳过下一个节点就行了

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let temp = new ListNode(-1)
    temp.next = head
    let fast = temp
    let slow = temp
    while(n !=0){
        fast = fast.next
        n--
    }
    while(fast.next != null){
        fast = fast.next
        slow = slow.next
    }
    slow.next = slow.next.next
     
    return  temp.next
};
```