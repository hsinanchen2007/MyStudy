![111.png](https://pic.leetcode-cn.com/f0bbd6341c964f40eb2744294def0844330a6c8ab96b72c994560c4e5d99fc94-111.png)

利用二叉搜索树性质，可以找到lowwerbound和upperbound.
lowwerbound指比target小的最大整数，upperbound指比target大的最小整数。
```
class Solution {
    private double lowwerBound;
    private double upperBound;
    public int closestValue(TreeNode root, double target) {        
        upperBound = root.val;
        lowwerBound = root.val;
        search(root, target);
        if( Math.abs(upperBound-target) < Math.abs(lowwerBound-target) ) {
            return (int)upperBound;
        }
        else {
            return (int)lowwerBound;
        }
    }
    
    private void search(TreeNode node, double target) {
        if( node == null ) {
            return ;
        }     
        if( node.val >= target ) {
            upperBound = node.val;
            search(node.left, target);
        }
        else {
            lowwerBound = node.val;
            search(node.right, target);
        }
                
    }
}
```
