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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {

        Queue<TreeNode> queue=new LinkedList();
        List<List<Integer>> list=new ArrayList();//存放结果

        if(root==null )
            return new ArrayList();
        else
        {
            queue.offer(root);
        }
        while(queue.size()>0)
        {
            int nodesNums=queue.size();
            List<Integer> listNode=new ArrayList<Integer>();

            while(nodesNums>0)
            {
                TreeNode node=queue.poll();//取出队尾
                listNode.add(node.val);
                if(node.left!=null)
                    queue.offer(node.left);
                if(node.right!=null)
                    queue.offer(node.right);
                nodesNums--;
            }
            list.add(0,listNode);

        }    
        return list;

    }
}
```