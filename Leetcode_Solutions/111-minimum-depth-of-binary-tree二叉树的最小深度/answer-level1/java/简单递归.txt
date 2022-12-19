```
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        if(root.left==null&&root.right==null)return 1;//到达叶子节点，高度至少是1
        if(root.left==null) return minDepth(root.right)+1;//未到叶子结点，情况一（左空，但右不空，继续遍历）
        if(root.right==null) return minDepth(root.left)+1;//未到叶子结点，情况二，...
        return Math.min(minDepth(root.left),minDepth(root.right))+1;//未到叶子结点，情况三，...
    }
}
```
