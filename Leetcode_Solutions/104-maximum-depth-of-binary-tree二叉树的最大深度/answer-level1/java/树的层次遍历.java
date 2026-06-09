### 解题思路
套用了一下树的层次遍历的代码

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
    public int maxDepth(TreeNode root) {
        if(root==null)  return 0;
        int level=0;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        TreeNode p=root;
        while(!queue.isEmpty())
        {
            int levelNum=queue.size(); //每层元素个数
            for(int i=0;i<levelNum;i++)
            {
                p=queue.remove();
                if(p.left!=null)
                {
                    queue.add(p.left);
                }
                if(p.right!=null)
                {
                    queue.add(p.right);
                }
            }
            level++;

        }
        return level;
    }
}
```