### 解题思路


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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        HashMap<TreeNode, TreeNode> parentMap = new HashMap<>();
        parentMap.put(root,null);
        LinkedList<TreeNode> stack = new LinkedList<>();
        // while(root != null){
        //     stack.addFirst(root);
        //     parentMap.put(root.left, root);
        //     root = root.left;
        // }
        // // 先序遍历
        // while(stack.size() != 0){
        //     root = stack.removeFirst();
        //     // 如果有右节点，则把右节点的所有左子节点都一下子全部压入栈中
        //     if(root.right != null){
        //         parentMap.put(root.right,root);
        //         TreeNode tmp = root.right;
        //         while(tmp != null){
        //             stack.addFirst(tmp);
        //             parentMap.put(tmp.left,tmp);
        //             tmp = tmp.left;
        //         }
        //     }
        // }



        parentMap.put(root, null);
        // root! = null 这个条件一定要加上，否则会出现死循环，至于原因，没明白
        while(root != null || !stack.isEmpty()){
            if(root != null){
                // 如果root不等于null，就一直往左下走
                stack.addFirst(root);
                parentMap.put(root.left,root);
                parentMap.put(root.right,root);
                root = root.left;
            }else{
                // 如果root等于null了，说明左遍历到了最底端null
                // 看是遍历 这个null节点的父节点的右节点

                // 1、首先取出null节点的父节点
                TreeNode endLeftNode = stack.removeFirst();
                // 2、然后看一看右子节点
                root = endLeftNode.right;
            }
        }


        // parentMap 中全部的节点的父节点存到了map中，就可以从p和q节点逆着父节点开始访问了
        
        HashSet<TreeNode> parentSet = new HashSet<>();
        while(p != null){
            parentSet.add(p);
            p = parentMap.get(p);
        }
        while(parentSet.contains(q) == false){
            q = parentMap.get(q);
        }
        
        return q;
    }
}
```