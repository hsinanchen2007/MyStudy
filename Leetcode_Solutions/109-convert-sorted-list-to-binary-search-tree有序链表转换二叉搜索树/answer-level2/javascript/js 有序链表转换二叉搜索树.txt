![image.png](https://pic.leetcode-cn.com/d414d9fc61621a1baa8f6d79828b2f3d4bbcbc04a31fc57414688f5f49b658b6-image.png)
1. 快慢指针找到链表中点
```
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
    let fn = (head, tail) => {
        if (head == tail) {
            return null
        }
        let fast = head
        let slow = head
        while (fast != tail && fast.next != tail) {
            slow = slow.next
            fast = fast.next.next
        }
        let root = new TreeNode(slow.val)
        root.left = fn(head, slow)
        root.right = fn(slow.next, tail)
        return root
    }
    return fn(head, null)
};
```
2.有序链接转为数组，空间换时间的解法
二叉搜索树中序排列是递增的，将有序链表转换为二叉搜索树，二叉搜索树的根节点一定是中间的值，二叉搜索树的左子树由有序链接起始位置到中间位置组成，右子树由中间位置至末尾部分组成，子树的规律也是这样，找到迭代的通项公式就可以开始写代码了
利用while循环将有序链接转换为数组，因为链表是递增的，所以数组也是递增的，寻找有序数组的中位数取index为数组长度/2向下取整的数字即可

```
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
    let getMid = (arr) => {
        return arr[Math.floor(arr.length/2)]
    }
    let list = []
    while(head) {
        list.push(head.val)
        head = head.next
    }
    let root = new TreeNode()
    let fn = (root, arr) => {
        if (arr.length === 0) return null
        let mid = getMid(arr)
        let idx = arr.indexOf(mid)
        root.val = mid
        root.left = fn(new TreeNode(), arr.slice(0, idx))
        root.right = fn(new TreeNode(), arr.slice(idx+1))
        return root
    }
    return fn(root, list)
};
```
