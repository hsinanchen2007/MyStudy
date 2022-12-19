### 解题思路
用Set的方法大家肯定都知道了，大家水平都很高啊，哈哈哈。

这里说下用BST的方法吧，中序遍历树，然后每次从root去查找k-node.val，这样算下来，空间复杂度是O(N)，时间复杂度是O(NlogN)，效率上确实差了一点，不过刷题嘛，重要的是思路。

这里有个注意的点，就是如果当前node.val刚好是k/2的话，要直接跳过，因为二叉搜索树中，是不可能有两个一模一样的值的。

执行的时间是2ms左右。

### 代码

```java
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
    public boolean findTarget(TreeNode root, int k) {
        if (root == null){
            return false;
        }
        TreeNode node = root;
        Deque<TreeNode> stack = new LinkedList<>();
        while (node != null || !stack.isEmpty()){
            if (node != null){
                stack.push(node);
                node = node.left;
            } else {
              node = stack.pop();
              int target = k - node.val;
              if (target != node.val){
                  if (searchBST(root,target) != null){
                      return true;
                  }
              }
              node = node.right;
            }
        }
        return false;
    }
    
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        TreeNode node = root;
        while (node != null) {
            if (val < node.val) {
                // 目标val比当前node.val要小，则表示目标在node的左子树中
                node = node.left;
            } else if (val > node.val) {
                // 目标val比当前node.val要大，则表示目标在node的右子树中
                node = node.right;
            } else {
                // val和node.val想等了，就找到了节点
                return node;
            }
        }
        return null;
    }
}
```