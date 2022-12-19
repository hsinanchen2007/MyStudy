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
    
    List<List<Integer>> res=new ArrayList<List<Integer>>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<Integer> list=new ArrayList<Integer>();
         int addResult=0;
         helper(root,sum,addResult,list);
         return res;
    }
    public void helper(TreeNode node, int sum,int addResult,List<Integer> list)
    {
        if(node==null)
        {
            return;
        }
        list.add(node.val);
        addResult+=node.val;
        if(addResult==sum&&node.left==null&&node.right==null)
        {
            res.add(new ArrayList(list));
            return;
        }
        helper(node.left,sum,addResult,list);
        if(node.left!=null)
        list.remove(list.size()-1);
        helper(node.right,sum,addResult,list);
        if(node.right!=null)
        list.remove(list.size()-1);
    }
}
```