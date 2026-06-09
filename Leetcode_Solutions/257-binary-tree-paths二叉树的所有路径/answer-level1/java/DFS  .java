### 解题思路
直接和先序遍历差不多的写法，判断为叶节点就说明到了终点就添加到集合中

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
    List<String> res = new ArrayList<String>();
    public List<String> binaryTreePaths(TreeNode root) {
        String path = new String("");
        helper(root,path);
        return res;
    }
    public void helper(TreeNode root,String path)
    {
        if(root==null)return;
        if(root.left==null && root.right==null)
        {
            path=path+root.val;
            res.add(path);
        }
        else
        {
            path=path+root.val+"->";
        }
        String path1 = new String(path);
        helper(root.left,path1);
        String path2 = new String(path);
        helper(root.right,path2);
    }
}
```