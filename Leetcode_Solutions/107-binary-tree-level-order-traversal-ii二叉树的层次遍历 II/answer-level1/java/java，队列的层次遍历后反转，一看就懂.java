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
        List<List<Integer>> res = new ArrayList<>();
        if(root==null)
            return res;
        Queue<TreeNode> queue = new  LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            List<Integer> temp = new ArrayList<>();
            int num = queue.size();
            for(int i = 0;i<num;i++)
            {
                TreeNode child = queue.peek(); 
                temp.add(child.val);
                if(child.left!=null)
                    queue.add(child.left);
                if(child.right!=null)
                    queue.add(child.right);
                queue.poll();
            }
            res.add(temp);
        }
        Collections.reverse(res);
        return res;
        // int len = res.size();
        // for(int i=0;i<len/2;i++)
        // {
        //      List<Integer> temp = res.get(len-i-1);
        //      res.set(len-i-1,res.get(i) );
        //      res.set(i,temp);
        // }
        // // if(len == 2)
        // // {
        // //     List<Integer> temp = res.get(1);
        // //      res.set(1,res.get(0));
        // //      res.set(0,temp);
        // // }
        // return res;
    }
}
```