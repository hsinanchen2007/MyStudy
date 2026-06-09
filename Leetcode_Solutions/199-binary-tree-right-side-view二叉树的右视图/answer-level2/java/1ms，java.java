### 解题思路
层序遍历，保存每一层最右边元素。

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
        LinkedList<TreeNode> queue=new LinkedList<>();
        List<Integer> result=new ArrayList<>();
        if(root==null)
        return result;
        TreeNode last=root;
        TreeNode first;
        queue.add(root);
        while(!queue.isEmpty())
        {
            first=queue.poll();
           
            
            if(first.left!=null)
            queue.add(first.left);
            if(first.right!=null)
            queue.add(first.right);
            if(last==first)
            {
              result.add(first.val);
              if(!queue.isEmpty())
              last=queue.getLast();
            }
        }
        return result;


    }
}
```