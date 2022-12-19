![image.png](https://pic.leetcode-cn.com/90f74bfc23d1776aa65371120ae9e8a60a4c91feacaf87fc22acd324c11350eb-image.png)

```
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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) return res;
        help(root, sum, new Stack<Integer>());
        return res;
    }
    private void help(TreeNode root, int sum ,Stack<Integer> context) {
        if (root == null) return;
        //叶子节点判断+回溯
        if (root.left == null && root.right == null) {
            if (root.val == sum) {
                context.push(root.val);
                res.add(new ArrayList(context));
                context.pop();
            }
            return;
        }
        //左子树中路径和等于给定值的结果
        context.push(root.val);
        help(root.right, sum-root.val, context);
        context.pop();
        //右子树中路径和等于给定值的结果
        context.push(root.val);
        help(root.left, sum-root.val, context);
        context.pop();
        
    }
}
```

![image.png](https://pic.leetcode-cn.com/ee12a83de79decfa86d3b70493bfbdc77788fc63ca20111400be83281add827b-image.png)

性能优化  list比stack快 原因:stack加锁了
```
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) return res;
        help(root, sum, new ArrayList<Integer>());
        return res;
    }
    private void help(TreeNode root, int sum ,ArrayList<Integer> context) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            if (root.val == sum) {
                context.add(root.val);
                res.add(new ArrayList(context));
                context.remove(context.size()-1);
            }
            return;
        }
        context.add(root.val);
        help(root.right, sum-root.val, context);
        context.remove(context.size()-1);
        context.add(root.val);
        help(root.left, sum-root.val, context);
        context.remove(context.size()-1);
        
    }
}
```
