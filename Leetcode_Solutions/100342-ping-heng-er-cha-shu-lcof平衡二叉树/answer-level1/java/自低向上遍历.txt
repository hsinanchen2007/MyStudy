### 解题思路
1.参考官方，自低向上遍历
2.递归到最深处开始比较结点高度
3.如果出现不平衡，说明整个二叉树是不平衡到，直接将高度置为0
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

   class TreeInfo{
       int height;
       boolean blance;
       public TreeInfo(int height,boolean blance){
          this.height=height;
          this.blance=blance;
       }
   }

   public TreeInfo isBalancedhelper(TreeNode root){
  if(root==null){
      return new TreeInfo(0,true);
  }
    TreeInfo left = isBalancedhelper(root.left);
    if(!left.blance){
        return new TreeInfo(0,false);
    }
     TreeInfo right =isBalancedhelper(root.right);
    if(!right.blance){
        return new TreeInfo(0,false);
    }
    int diff = left.height-right.height;
    if(Math.abs(diff)<2){
              return new TreeInfo(Math.max(left.height,right.height)+1,true);
    }
        return new TreeInfo(0,false);
   }

    public boolean isBalanced(TreeNode root) {
     return isBalancedhelper(root).blance;
    }
}
```