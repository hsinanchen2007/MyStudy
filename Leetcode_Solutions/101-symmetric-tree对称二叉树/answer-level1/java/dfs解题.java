### 解题思路
首先对根节点的左子树按照：根节点-左节点-右节点，dfs访问所有点，得到左子树的遍历结果，然后对根节点的右
子树按照：根节点-右节点-左节点，dfs遍历的同时比较左子树遍历结果与当前节点，若有不同立马返回结果。

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
    public boolean isSymmetric(TreeNode root) {
        if(root==null){
            return true;
        }
        LinkedList<TreeNode> leftList=new LinkedList<>();
        dfsPri(root.left,leftList);
        return dfsLast(root.right,leftList);
    }
    public void  dfsPri(TreeNode node,LinkedList<TreeNode> list){
        list.add(node);
        if(node==null){
            return;
        }
        dfsPri(node.left,list);
        dfsPri(node.right,list);
    }
    public boolean dfsLast(TreeNode node,LinkedList<TreeNode> list){
        if(list.isEmpty()){
            return false;
        } 
        TreeNode nodeInList=list.remove();
        // 比较是否为空
        if(node==null){
            if(nodeInList==null){
                return true;
            } else{
                return false;
            }
        } else if(nodeInList==null){
            return false;
        }
        // 比较值
        if(node.val!=nodeInList.val){
            return false;
        }
        // 比较子树
        boolean rightResult=dfsLast(node.right,list);
        if(!rightResult){
            return false;
        }
        return dfsLast(node.left,list);
        
    }
}
```