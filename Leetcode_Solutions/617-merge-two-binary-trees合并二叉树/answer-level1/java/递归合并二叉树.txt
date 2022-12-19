```
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        //null值判断, 如果全null返回null, 如果其中一个为null则返回另一个树
        if(t1 == null) {
            if(t2 == null) {
                return null;
            } else {
                return t2;
            }
        }
        if(t2 == null) {
            if(t1 == null) {
                return null;
            } else {
                return t1;
            }
        }

        //一般情况求解
        TreeNode t3 = new TreeNode(t1.val + t2.val);    //先创建结果树节点
        t3.left = mergeTrees(t1.left, t2.left);     //结果树左节点用递归求解, 特殊情况已经在上面考虑
        t3.right = mergeTrees(t1.right, t2.right);
        return t3;
    }

}
```
