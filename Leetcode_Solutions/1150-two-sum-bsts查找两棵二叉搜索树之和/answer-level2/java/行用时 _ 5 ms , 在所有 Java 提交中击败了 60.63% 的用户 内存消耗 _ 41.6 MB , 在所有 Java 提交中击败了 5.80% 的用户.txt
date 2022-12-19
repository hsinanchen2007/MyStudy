### 解题思路
遍历一个树，从另一个树里找对应的差，时间复杂度应该是NLogM

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
 import java.lang.*;
class Solution {
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        if(root1==null|root2==null){
            return false;
        }
        //这里就是遍历一下，用了土逼层序遍历，
        LinkedList<TreeNode> nodes = new LinkedList();
        nodes.addFirst(root1);
        while(nodes.size()!=0){
            LinkedList<TreeNode> currentLevel = new LinkedList();
            for(int i=0;i<nodes.size();i++){
                TreeNode node = nodes.removeFirst();
                if(binarySearch(root2,target-node.val)!=null){
                    return true;
                }
                if(node.left!=null){
                    currentLevel.add(node.left);
                }
                if(node.right!=null){
                    currentLevel.add(node.right);
                }
            }
            nodes.addAll(currentLevel);
        }
        return false;
    }

    public TreeNode binarySearch(TreeNode root,int target){
        if(root==null||root.val==target){
            return root;
        }
        if(root.val>target){
            return binarySearch(root.left,target);
        }else{
            return binarySearch(root.right,target);
        }
    }
}
```