### 解题思路
使用queue

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
    public int[] levelOrder(TreeNode root) {
        if(root == null)
            return new int[0] ;
        List<Integer> ret = new ArrayList<Integer>() ;
        ArrayDeque<TreeNode> deq = new ArrayDeque<TreeNode>() ;
        deq.addLast(root) ;
        while (!deq.isEmpty()) {
            TreeNode popNode = deq.pollFirst() ;
            ret.add(popNode.val) ;
            if (popNode.left != null)
                deq.addLast(popNode.left) ;
            if (popNode.right != null)
                deq.addLast(popNode.right) ;
        }

        int[] retFinal = new int[ret.size()] ;
        for (int i=0 ; i< ret.size() ; i++) {
            retFinal[i] = ret.get(i) ;
        }
        return retFinal ;
    }
}
```