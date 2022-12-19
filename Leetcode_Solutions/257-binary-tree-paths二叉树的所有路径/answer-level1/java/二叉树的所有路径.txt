### 解题思路
此题利用了java值传递的思想,字符串在方法体内改变不会影响外面的字符串

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
    
    

    public List<String> construct_paths(TreeNode root,String path,List<String> paths) {
        if(root != null){
            path += root.val;
            if(root.left == null && root.right == null){
                //叶子节点把路径加入list
                paths.add(path);
            }else{
                //不是叶子节点
                path += "->";
                construct_paths(root.left,path,paths);
                construct_paths(root.right,path,paths);
            }


        }
        return paths;
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        construct_paths(root, "", paths);
        return paths;
    }
}
```