### 解题思路
1. 设置缓冲区arr, 把链表的每个节点val作为arr的key, 将value设置为1
2. 查找arr[current.val]. 如果有值为1的元素, 说明重复, 需要删除

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

var removeDuplicateNodes = function(head) {
    // 缓冲区
    let arr = [];
    let prev = null;
    let current = head;
    while (current !== null) {
        if (arr[current.val] > 0) {
            // 有重复的
            prev.next = current.next;
            current = prev.next;
        } else {
            arr[current.val] = 1;
            prev= current;
            current = current.next;
        }
    }
    return head;
};
```