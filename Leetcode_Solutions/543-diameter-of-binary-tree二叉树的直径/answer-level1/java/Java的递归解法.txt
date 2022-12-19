本题的目标是找树的最大直径，首先我们要明确：
```
一个节点的最大直径 = 它左树的高度 +  它右树的高度
```
然后其实就是遍历每个节点，找出所有节点中的直径的最大值即可。

```java
class Solution {
    //设置一个类变量，用于记录最大直径
    private int max = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return max;
    }
    
    private int depth(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftDepth = depth(root.left);
        int rightDepth = depth(root.right);
        //max记录当前的最大直径
        max = Math.max(leftDepth + rightDepth, max);
        //由于我计算的直径是左树高度+右树高度，所以这里返回当前树的高度，以供使用
        return Math.max(leftDepth, rightDepth) + 1;
    }
}
```