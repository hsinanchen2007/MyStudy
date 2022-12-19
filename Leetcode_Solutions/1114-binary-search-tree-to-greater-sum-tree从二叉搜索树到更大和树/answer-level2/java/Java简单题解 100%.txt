```
class Solution {
    /**
    **遍历并更新节点，返回子树最大值
    **/
    private int fillAndGetMax(TreeNode root, int b){
        if(root == null){
            return b;
        }
        root.val += fillAndGetMax(root.right, b);
        return fillAndGetMax(root.left, root.val);
    }
    public TreeNode bstToGst(TreeNode root) {
        fillAndGetMax(root, 0);
        return root;       
    }
}
```
![10383.PNG](https://pic.leetcode-cn.com/15aea2fa55852d18279a05e0d07566efc0f77bb0aae4d73002ad3e1e423e9228-10383.PNG)


