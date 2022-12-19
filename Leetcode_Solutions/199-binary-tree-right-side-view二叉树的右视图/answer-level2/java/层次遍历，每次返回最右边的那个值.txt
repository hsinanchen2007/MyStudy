### 解题思路
rt

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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> l = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode tn = root;
        if(root == null)
            return l;
        q.add(tn);
        while(!q.isEmpty())
        {
            int size = q.size();
            TreeNode tmp = null;
            for(int i = 0;i < size;i++)
            {
                tmp = q.poll();
                if(i == size-1)
                {
                    l.add(tmp.val);
                }
                if(tmp.left!=null)
                {
                    q.add(tmp.left);
                }
                if(tmp.right!=null)
                {
                    q.add(tmp.right);
                }
            }
        }
        return l;
    }
}
```