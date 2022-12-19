### 解题思路
执行用时 : 1 ms , 在所有 Java 提交中击败了 100.00% 的用户 
内存消耗 : 37 MB , 在所有 Java 提交中击败了 100.00% 的用户

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
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null){
            return null;
        }
        LinkedList<TreeNode> nodes = new LinkedList();
        nodes.add(root);
        while(nodes.size()!=0){
            
            ArrayList<TreeNode> currentFloor = new ArrayList();
            for(int i = 0;i<nodes.size();i++){
                TreeNode node = nodes.poll();
                TreeNode temp = node.left;
                node.left = node.right;
                node.right = temp;
                if(node.left!=null){
                    currentFloor.add(node.left);
                }
                if(node.right!=null){
                    currentFloor.add(node.right);
                }
            }
            nodes.addAll(currentFloor);
        }

        return root;
    }
}
```