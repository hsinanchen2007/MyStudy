### 解题思路
两种思路
1. 后序遍历的思路（左，右，中）
首先遍历左子树，并且入栈，当左子树为空时，取出栈顶的元素，但不出栈。
此时做判断：（1）.右子树为空，直接遍历取出的元素，并且从栈顶移除该元素，并用last标记该元素
            （2）.右子树被访问过（通过last来判断），此时遍历取出的元素，并从栈顶移除该元素，并用last标记
            （3）.右子树不为空且没有被访问，我们就去访问右子树。
2. 深度遍历 中-右-左
将遍历的元素“头插”既可逆序为 左 右 中的后序遍历。

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<TreeNode> list = new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        TreeNode last = null;
        while (!list.isEmpty() || root != null){
            if (root != null){
                list.add(root);
                root = root.left;
            }
            else {
                root = list.get(list.size() - 1);
                if (root.right != null && root.right != last){
                    root = root.right;
                }
                else {
                    last = root;
                    res.add(root.val);
                    list.remove(list.size()-1);
                    root = null;
                }
            }
        }
        return res;
    }
    
    private List<Integer> x(TreeNode root){
        List<TreeNode> list = new LinkedList<>();
        List<Integer> output = new LinkedList<>();
        if (root == null)
            return output;
        list.add(root);
        while (!list.isEmpty()){
            TreeNode treeNode = list.remove(list.size() - 1);
            output.add(0,treeNode.val);
            if (treeNode.left != null)
                list.add(treeNode.left);
            if (treeNode.right != null)
                list.add(treeNode.right);
        }
        return output;
    }
}
```