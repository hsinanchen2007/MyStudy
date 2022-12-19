### 解题思路
此处采用的是深度优先算法，访问顺序是 根节点 --》 右子树 --》 左子树，那么很明显，每次访问一层的，第一个访问节点就是我们要找的节点。
本题的关键点，在于这个算法，每深入一层，如何判断第一个访问的节点。

如何判断第一个访问的节点？
我们第一个访问的节点肯定是要进入我们的返回值数组result，那么当我们发现我们的深度等于当前返回值数组长度时，说明我们正在访问下一个深度的第一个节点。
举例：
  访问根时，深度1，但此时，并没有将其放入result，此时result的size是0，访问之后将深度记录为1.

由于我们总是访问根之后，先访问右子树，所以右子树的根节点，一定是第一个将深度加1的。
访问左子树时，右子树处，已经将depth增加，不会造成重复累计。
  

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

    List<Integer> result = new ArrayList<Integer>();

    public List<Integer> rightSideView(TreeNode root) {
        dfs(root,0);
        return result;

    }

    public void dfs(TreeNode root, int depth){
         if(root == null){
             return;
         }
        //如何判断第一个访问的节点
        //先根节点
         if(depth == result.size()){
             result.add(root.val);
         }

         depth++;

         //第二个访问右子树
         if(root.right != null){
             dfs(root.right , depth);
         } 

         //再访问左子树
         if(root.left != null){
             dfs(root.left,depth);
         }
    }


}
```