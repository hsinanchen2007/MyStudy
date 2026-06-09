### 解题思路
和两数之和的逻辑其实差不多，二叉搜索树查找一个节点的时间是O(logN)级别的，然后中序遍历一个二叉树是O(N)级别，这个思路了就是利用了二叉搜索树的两个特点。算是切合题意了，但是不一定是最优解。

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
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        if (root1 == null || root2 == null){
            return false;
        }
        TreeNode node = root1;
        Deque<TreeNode> stack = new LinkedList<>();// 双端队列模拟栈
        while(node != null || !stack.isEmpty()){
            stack.push(node);
            node = node.left;
            while (node == null && !stack.isEmpty()){
                node = stack.pop();
                int value = target - node.val;
                TreeNode node2 = searchBST(root2,value);
                if (node2 != null){
                    return true;
                }
                node = node.right;
            }
        }
        return false;
    }
    
    /**
     * 查询二叉搜索树的节点
     *
     * @param root 根节点
     * @param val 值
     * @return val所在的节点
     */
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null) {
            return null;
        }
        TreeNode node = root;
        while (node != null) {
            if (val < node.val) {
                node = node.left;
            } else if (val > node.val) {
                node = node.right;
            } else {
                return node;
            }
        }
        return null;
    }
}
```