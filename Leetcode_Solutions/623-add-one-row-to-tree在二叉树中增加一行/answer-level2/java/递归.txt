### 解题思路
此处撰写解题思路

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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        return addOneRow2(root,v,d,1);
    }
    //设置了方向的
    public TreeNode addOneRow2(TreeNode root,int v,int d,int direction){
        if(root==null){
            if(d==1){
                return new TreeNode(v);
            }
            else{
                return null;
            }
        }
        if(d==1){
            if(direction==1){
                TreeNode result=new TreeNode(v);
                result.left=root;
                return result;
            }
            else{
                TreeNode result=new TreeNode(v);
                result.right=root;
                return result;
            }
        }
        if(d==2){
            root.left=addOneRow2(root.left,v,1,1);
            root.right=addOneRow2(root.right,v,1,2);
            return root;
        }
        else{
            root.left=addOneRow2(root.left,v,d-1,1);
            root.right=addOneRow2(root.right,v,d-1,1);
            return root;
        }
    }
}
```