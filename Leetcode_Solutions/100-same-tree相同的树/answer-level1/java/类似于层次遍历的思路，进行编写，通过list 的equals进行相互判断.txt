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
  public boolean isSameTree(TreeNode p, TreeNode q) {

        List<Integer> p1 ;
        List<Integer> q1 ;
        p1 = levelOrder(p);
        q1 = levelOrder(q);


        return  p1.equals(q1);
    }

    private List<Integer> levelOrder(TreeNode root) {
        List<Integer> result  = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
  if (root == null){
            return result;
        }
        q.add(root);

        while (!q.isEmpty()){
            TreeNode cur = q.remove();
            result.add(cur.val);

            if (cur.left != null){
                q.add(cur.left);
            }

            if (cur.right != null){
                q.add(cur.right);
            }
            if (cur.right != null && cur.left == null){
                result.add(-1);
            }
        }
        return result;
    }

}
```