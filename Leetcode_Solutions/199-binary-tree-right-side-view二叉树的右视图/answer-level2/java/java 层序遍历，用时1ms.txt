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
    public List<Integer> rightSideView(TreeNode root) {//层序遍历，将每层最右边的元素加入ans 
        Queue<TreeNode> q=new LinkedList<>();
        List<Integer> ans=new ArrayList<>();
        if(root==null)
        return ans;
        q.offer(root);
        while(!q.isEmpty())
        {
            int size=q.size()-1;
            for(int i=0;i<=size;i++)//遍历当前层，加入最后一个节点
            {
                TreeNode temp=q.poll();
                if(i==size)
                 ans.add(temp.val);
                if(temp.left!=null)
                 q.offer(temp.left);
                if(temp.right!=null)
                 q.offer(temp.right);
            }
        }
        return ans;
    }
}
```