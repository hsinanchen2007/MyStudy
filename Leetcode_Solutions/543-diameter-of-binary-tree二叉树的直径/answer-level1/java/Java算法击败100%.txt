解题思路：看到这道题的时候第一反应就是只要计算这个最长直径一定是在根节点的两侧的。所以只要计算出左子树的深度和右子树深度相加就可以得到这道题的解了。而计算二叉树深度用以下算法即可：
```
public class Solution {
    public int TreeDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        int left=TreeDepth(root.left);
        int right=TreeDepth(root.right);
        return left>right?left+1:right+1;
    }
}
```
测试了给出的给出的基本示例成功通过，提交后发现有问题。想了下原来是因为树的最大直径可能是不过跟节点的（当左子树很矮右子树有两条很高的分支）。因此我们需要对算法进行一点小小的改进，引入一个变量max用于记录得到的最大的直径。下面放码过来：
```
class Solution {
    int max = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null){
            return 0;
        }
        treeDeepth(root);
        return max;
    }
    private int treeDeepth(TreeNode node){
        if(node == null){
            return 0;
        }
        int left = treeDeepth(node.left);
        int right = treeDeepth(node.right);
        if((left+right)>max){
            max = left+right;
        }
        return left > right ? left+1:right+1;
    }
}
```

