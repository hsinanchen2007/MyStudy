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
    public int countNodes(TreeNode root) {
        if(root==null)return 0;
        return bs(root,1,mostLeftLevel(root,1));
    }
    //node为当前节点，level是其层数，h是树的深度
    public int bs(TreeNode node,int level,int h){
        if(level==h)return 1;
        if(mostLeftLevel(node.right,level+1)==h)
        //1<<(h=level),1向左移x位，就是2的x次幂
        return (1<<(h-level))+bs(node.right,level+1,h);
        else return (1<<(h-level-1))+bs(node.left,level+1,h);


    }
    public int mostLeftLevel(TreeNode node,int level){
        while(node!=null){
            level++;
            node=node.left;
        }
        return level-1;
    }
}
```