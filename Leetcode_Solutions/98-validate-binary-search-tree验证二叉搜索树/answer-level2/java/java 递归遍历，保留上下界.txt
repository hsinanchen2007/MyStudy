### 解题思路

1、对于一颗搜索二叉树而言，每个节点都存在一个上限和下限，假定上限定义为upper,下限定义为lower
                root
        left                            right
left.left left.right    right.left  right.right

    那么对于left而言,下限为null,上限为rootVal
    对于right而言，下限为rootVal,上限为null
    对于left的右边子节点而言,下限为left.val,上限为rootVal,而这里的rootVal就是来自于left的传承
    对于right的左边子节点而言,下限为rootVal,,上限为right.val,这里的rootVal也是来自于right的传承
   所以我们有了下面的方法
    public boolean help(TreeNode root,Integer  upper,Integer lower){
          if(root==null){
              return true;
         }
         int rootVal = root.val;
        if(upper!=null && root>=upper ) return false;
        if(lower!=null&&root<=lower)  return false;
        if(!help(root.left,rootVal,lower)) return false;
       if(!help(root.right,upper,rootVal)) return false;
         return true;  
    }
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

private boolean isValidBST0(TreeNode root,Integer lower,Integer upper){
        if(root==null){
            return true;
        }
        if(lower!=null && root.val<=lower){
            return false;
        }
        if(upper!=null && root.val>=upper){
            return false;
        }
        int rootVal = root.val;
        if(!isValidBST0(root.left,lower,rootVal)){
            return false;
        }
        if(!isValidBST0(root.right,rootVal,upper)){
            return false;
        }

        return true;
    }

    public boolean isValidBST(TreeNode root) {
         if(root==null){
            return true;
        }
        return isValidBST0(root,null,null);
    }
}
```