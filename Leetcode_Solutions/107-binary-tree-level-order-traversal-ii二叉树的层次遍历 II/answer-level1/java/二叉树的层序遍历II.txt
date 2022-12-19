### 解题思路
    本题考查二叉树的层序遍历，用队列这个数据结构实现即可。其实还是从顶层到底层按层遍历。只不过最后插入list列表时从列表头部插入即可。
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root==null)
            return new ArrayList<>();
        List<List<Integer>> ans=new ArrayList<>();
        Queue <TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            int level=queue.size();
            List<Integer> list=new ArrayList<>();
            while(level>0)
            {
                TreeNode node=queue.remove();
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                list.add(node.val);
                level--;
            }
            ans.add(0,list);
        }
        return ans;
    }
}
```