### 解题思路
在返回答案前，翻转奇数列元素

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> tree=new LinkedList<TreeNode>();
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        if(root==null)
        return ans;
        tree.add(root);
        int level=0; 
        while(!tree.isEmpty())
        {
            ans.add(new ArrayList<Integer>());//新加一层
            int length=tree.size()-1;//获取当前层的节点数
            for(int i=0;i<=length;i++)
           { 
             TreeNode p=tree.remove();
             ans.get(level).add(p.val);//当前节点加入列表
             if(p.left!=null)
             tree.add(p.left);//子节点入队列
             if(p.right!=null)
             tree.add(p.right);
           }
           level++;//进入下一层
        }
        for(int j=0;j<ans.size();j++)//在102题基础上将奇数列翻转
        if(j%2==1)
         Collections.reverse(ans.get(j));
        return ans;

    }
}
```