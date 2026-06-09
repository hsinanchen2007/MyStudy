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
    Map<String,Integer> count;
    List<TreeNode> ans;
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        count=new HashMap<>();
        ans=new ArrayList<>();
        collect(root);
        return ans;
    }

    public String collect(TreeNode root)
    {
        if(root==null)
            return "#";
        String serial=root.val+","+collect(root.left)+","+collect(root.right);
        count.put(serial,count.getOrDefault(serial,0)+1);
        if(count.get(serial)==2)
            ans.add(root);
        return serial;
    }
}
```