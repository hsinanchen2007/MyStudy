### 解题思路
刚接触递归，用递归做的第一道题纪念以下，编之前自己都不晓得对不对；
个人觉得做递归的题不要纠结于运算过程，抽象的来看待递归，这里说的抽象是当该问题确实能用递归解决时，就直接去找递归的要素，不要考虑具体程序执行过程；
（1）判断问题是否为递归问题，此问题每一步执行的过程相同-都是左右节点的最大深度+1即为当前节点深度；
（2）递归结束的条件-最底下的节点为空时，返回深度0；最初我设置(root.left == null && root.right == null) return 1，但是如果没有根节点的情况下，深度其实为0的，忽略了这种情况，所以改成root==null,return 0.
能够归纳出（1）（2）这个问题其实就出来了，小白的想法，可能递归多做一些就会有更好的见解，这里只是分享下目前的思考。

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
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }else{
            int depth = Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
            return depth;
        }
    }
}
```