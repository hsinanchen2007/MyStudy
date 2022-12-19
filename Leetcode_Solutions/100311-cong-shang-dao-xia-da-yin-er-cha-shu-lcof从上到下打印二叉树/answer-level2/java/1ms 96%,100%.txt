### 解题思路
简单队列思想

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
    public int[] levelOrder(TreeNode root) {
        if (root==null)
            return new int[0];
        List<TreeNode> list=new ArrayList<>();
        int i=0;
        list.add(root);
        while (i<list.size()){
            TreeNode mid=list.get(i);
            if (mid.left!=null)
                list.add(mid.left);
            if (mid.right!=null)
                list.add(mid.right);
            i++;
        }
        int [] res=new int[list.size()];
        for (int j=0;j<list.size();j++)
            res[j]=list.get(j).val;
        return res;
    }
}
```