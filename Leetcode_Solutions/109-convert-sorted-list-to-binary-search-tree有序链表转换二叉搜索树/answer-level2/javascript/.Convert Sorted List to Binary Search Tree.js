### 解题思路
[https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-by-/](官方写法)改写js
利用快慢指针找到中间值，即为根，先找到的根故前序遍历生成树，注意这里的关键点是找中间值的时候，要用一个额外的指针记录中间值前一个节点，目的是切断前后节点的关联

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
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {TreeNode}
 */
var sortedListToBST = function(head) {
    if (head === null) return null
    let mid = findMiddle(head)
    let root = new TreeNode(mid.val)
    if (head === mid) return root
    root.left = sortedListToBST(head)
    root.right = sortedListToBST(mid.next)
    function findMiddle(head) {
        let slow = head, fast = head, pre = null
        while(fast!== null && fast.next !== null) {
            pre = slow
            slow = slow.next
            fast = fast.next.next
        }
        if (pre !== null) {
            pre.next = null
        }
        return slow
    }
    return root
    
};
```