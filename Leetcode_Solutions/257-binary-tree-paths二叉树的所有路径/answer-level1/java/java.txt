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
    public void TreeAllPath(TreeNode root,String path,LinkedList<String>paths){
        if(root!=null){
            path+=Integer.toString(root.val);
            if(root.left==null&&root.right==null){
                paths.add(path);
            }
            else{
                path+="->";
                TreeAllPath(root.left,path,paths);
                TreeAllPath(root.right,path,paths);
            }
        }
    }
    public List<String> binaryTreePaths(TreeNode root) {
    LinkedList<String>paths=new LinkedList();
    TreeAllPath(root,"",paths);
    return paths;
    }
}
```