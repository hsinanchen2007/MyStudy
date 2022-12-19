### 解题思路
- 使用快慢指针，每次快指针走两步，慢指针走一步。
- 假设表头到入环点是距离为 `D`，`D` 到第一次快慢指针相遇的点为 `S1` ，`S1` 到入环点距离为 `S2`
- 到第一次相遇点，慢指针走的距离为 `D + S1`；快指针走的距离为 `D + S1 + S2 + S1`
- 快指针走的距离是慢指针的两倍，所以 `2 * (D + S1) = D + S1 + S2 + S1`，得出：`D = S2`
- 所以，两个点分别从表头和第一次相遇点出发，每次走一步，相遇的地方就是入环点

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
var detectCycle = function(head) {

    // 找出第一次相遇的点
    let fast = head, slow = head, fistMeet = null
    while(slow && fast && fast.next) {
        slow = slow.next
        fast = fast.next.next
        if(slow === fast) {
            fistMeet = slow
            break
        }
    }

    if(!fistMeet) {
        return null
    }

    while(fistMeet && head) {
        if(fistMeet === head) {
            return head
        }
        fistMeet = fistMeet.next
        head = head.next
    }
    return null
}
```