### 解题思路
此处撰写解题思路

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
        
    Queue<TreeNode> queue=new LinkedList();
    int deepth=0;

    if(root==null)
        {
            return 0;
        }
    else{
        queue.offer(root);
    }

    while(queue.size()>0)
        {
            int nodeCounts=queue.size();
            deepth++;
            while(nodeCounts>0)
            {
                TreeNode node=queue.poll();
                if(node.left!=null)
                    queue.offer(node.left);
                if(node.right!=null)
                    queue.offer(node.right);
                nodeCounts--;
            }

        }
        return deepth;
    }

}
```