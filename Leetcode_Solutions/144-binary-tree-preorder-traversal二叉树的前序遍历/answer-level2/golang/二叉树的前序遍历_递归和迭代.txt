### 解题思路


### 代码

#### 迭代
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
    public List<Integer> preorderTraversal(TreeNode root) {

        List<Integer> retList = new ArrayList<Integer>();
        if (root != null) {
            TreeNode node = root;
            Stack<TreeNode> stack = new Stack<TreeNode>();
            stack.add(node);
            while (!stack.isEmpty()) {
                node = stack.pop();
                retList.add(node.val);
                if (node.right != null) {
                    stack.add(node.right);
                }
                if (node.left != null) {
                    stack.add(node.left);
                }
            }
        }
        return retList;
    }
}
```

#### 递归
```golang
func preorderTraversal(root *TreeNode) []int {

    if root == nil {
        return []int{}
    }
    ret := []int{}
    preorder(root, &ret)
    return ret
}

func preorder(node *TreeNode, ret* []int) {

    if node == nil {
        return
    }
    *ret = append(*ret, node.Val)
    preorder(node.Left, ret)
    preorder(node.Right, ret)
}
```