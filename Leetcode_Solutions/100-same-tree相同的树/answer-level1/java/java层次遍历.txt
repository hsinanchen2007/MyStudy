### 解题思路
java 层次遍历

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Queue<TreeNode>  root1=new LinkedList<>();
        Queue<TreeNode>  root2=new LinkedList<>();
        root1.offer(p);
        root2.offer(q);
        while(!root1.isEmpty()||!root2.isEmpty()){
            TreeNode temp1=root1.poll();
            TreeNode temp2=root2.poll();
            if(temp1==null&&temp2==null){
                continue;
            }
            if(temp1==null||temp2==null){
                return false;
            }
            if(temp1.val!=temp2.val){
                return false;
            }
           
            root1.offer(temp1.left);
            root1.offer(temp1.right);
            root2.offer(temp2.left);
            root2.offer(temp2.right);
        }

        return root1.isEmpty()&&root2.isEmpty();

    }
}
```