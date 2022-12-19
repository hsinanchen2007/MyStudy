重点在于构建private void  listNode(List<TreeNode> nodes, List<List<Integer>> result)这样一个辅助函数。
辅助函数的入参第一个表示每一层的节点,第二个表示最终的结果。
每次把当前层的节点值加到最终结果后,获取节点的下一层节点，递归调用，直到下一层节点为空。

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

   private void  listNode(List<TreeNode> nodes, List<List<Integer>> result){
         if(nodes.isEmpty()){
             return;
         }
         List<Integer> list = new ArrayList<Integer>();
         List<TreeNode> childrens = new ArrayList<TreeNode>();
         for(TreeNode treeNode:nodes){
                list.add(treeNode.val);
                if(treeNode.left!=null){
                    childrens.add(treeNode.left);
                }
                if(treeNode.right!=null){
                    childrens.add(treeNode.right);
                }
         }
         result.add(list);
         listNode(childrens,result);        
   }

    public List<List<Integer>> levelOrder(TreeNode root) {
            List<List<Integer>> result = new ArrayList<List<Integer>>();
            if(root == null){
                return result;
            }
            listNode(Arrays.asList(root),result);
            return result;
    }
}
```