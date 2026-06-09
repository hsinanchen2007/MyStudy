## 解题方案

### 思路

- 标签：DFS
- 终止条件、返回值和递归过程：
  - 当前节点root为空时，说明此处树的高度为0，0也是最小值
  - 当前节点root的左子树和右子树都为空时，说明此处树的高度为1，1也是最小值
  - 如果为其他情况，则说明当前节点有值，且需要分别计算其左右子树的最小深度，返回最小深度+1，+1表示当前节点存在有1个深度
- 时间复杂度：O(n)，n为树的节点数量

### 代码


```Java []
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        if(root.left == null && root.right == null) {
            return 1;
        }
        int ans = Integer.MAX_VALUE;
        if(root.left != null) {
            ans = Math.min(minDepth(root.left), ans);
        }
        if(root.right != null) {
            ans = Math.min(minDepth(root.right), ans);
        }
        return ans + 1;
    }
}
```

```JavaScript []
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if(root == null) {
        return 0;
    }
    if(root.left == null && root.right == null) {
        return 1;
    }
    let ans = Number.MAX_SAFE_INTEGER;
    if(root.left != null) {
        ans = Math.min(minDepth(root.left), ans);
    }
    if(root.right != null) {
        ans = Math.min(minDepth(root.right), ans);
    }
    return ans + 1;
};
```


### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/5ba456b67014e0c31034e05c414bfc4b62bb13d2b51a8f683890630efab447c5-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/1c7c463b3aee81c01efa2ab2eb6d15d6dd7f4a5a34ae8e272c16b861568d0107-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/d73265498b20c20e8caf79875b0190ca5a5e0049e8a14518164ac7b85889ffae-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/ff8081b7d9fb45943c27e8b16eb1a61692b45b28b8c5966f297945eb17db78cf-frame_00004.png)>

点击我的头像加关注，和我一起打卡天天算法