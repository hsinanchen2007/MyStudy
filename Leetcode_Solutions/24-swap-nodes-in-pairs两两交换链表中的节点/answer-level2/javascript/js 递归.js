### 解题思路
![image.png](https://pic.leetcode-cn.com/b04701be73de0cd0dfef3139f50338d3cb4fd91ec59596455e2855b5dc59e104-image.png)

递归反转

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
var swapPairs = function(head) {
    if (!head) return null;
    if (!head.next) return head;
    let res = head.next;
    function swap(node, prev) {
        let next = node.next;
        if (!next) return;
        node.next = node.next.next;
        next.next = node;
        if (prev) {
            prev.next = next;
        }
        if (node.next) {
            swap(node.next, node)
        }
    }
    swap(head, null);
    return res
};
```