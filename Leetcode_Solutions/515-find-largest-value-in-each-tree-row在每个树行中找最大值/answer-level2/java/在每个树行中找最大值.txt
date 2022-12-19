### 解题思路
层序遍历，用一个变量max记录每一层的最大值，遍历完一层将max添加到列表中。

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
    public List<Integer> largestValues(TreeNode root) {
     //本题是一个典型的二叉树层次遍历问题
     List<Integer> res=new ArrayList<Integer>();
     if(root==null)
        return res;
    Queue<TreeNode> queue=new LinkedList<>();
    queue.add(root);
    while(!queue.isEmpty())
    {
        int size=queue.size();
        int max=Integer.MIN_VALUE;
        while(size>0)
        {
            TreeNode node=queue.remove();
            max=Math.max(max,node.val);
            if(node.left!=null)
                queue.add(node.left);
            if(node.right!=null)
                queue.add(node.right);
            size--;
        }
        res.add(max);
    }
    return res;
    }
}
```