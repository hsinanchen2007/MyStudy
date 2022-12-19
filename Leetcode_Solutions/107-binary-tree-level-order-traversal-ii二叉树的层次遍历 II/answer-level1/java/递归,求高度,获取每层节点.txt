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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result= new ArrayList<>();
        for(int i=getHeight(root);i>=1;i--){
             List<TreeNode> temp =   new ArrayList<>();
             getLevel(root,i,temp);
             result.add(temp.stream().map(r -> r.val).collect(Collectors.toList()));
        }
        return result;
    }

    public int getHeight(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return Math.max(leftHeight,rightHeight)+1;
    }

    public void getLevel(TreeNode root,int level,List<TreeNode> result){
        if(root==null){
            return;
        }
        if(level==1){
            result.add(root);
        }else{
            getLevel(root.left,level-1,result);
            getLevel(root.right,level-1,result);
        }
    }

}
```