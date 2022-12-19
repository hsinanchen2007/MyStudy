### 解题思路

利用 ``广度优先搜索``，一层层遍历，之后按层生成 ``链表`` 即可。

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {TreeNode} tree
 * @return {ListNode[]}
 */
var listOfDepth = function(tree) {
    let res = []
    let queue = [tree]
    while (queue.length) {
        let length = queue.length
        let head = null
        let curr = null
        let prev = null
        while (length--) {
            let { val, left, right } = queue.shift()
            curr = new ListNode(val)
            if (prev) {
                prev.next = curr
            } else {
                head = curr
            }
            prev = curr
            if (left) {
                queue.push(left)
            }
            if (right) {
                queue.push(right)
            }
        }
        res.push(head)
    }
    return res
};
```