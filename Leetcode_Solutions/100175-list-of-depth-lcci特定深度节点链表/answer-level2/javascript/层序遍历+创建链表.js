### 解题思路
此处撰写解题思路

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

    let ans = []
    if (!tree) return ans

    let queue = []
    queue.push(tree)

    while (queue.length) {
        let dummyHead = {}, tail = dummyHead;   
        for (let i = 0, n = queue.length; i < n; i++) {
            let node = queue.shift()
            tail = tail.next = new ListNode(node.val)

            if (node.left) queue.push(node.left)
            if (node.right) queue.push(node.right)
        }

        ans.push(dummyHead.next);
    }

    return ans
};
```