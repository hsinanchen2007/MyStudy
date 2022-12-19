### 解题思路
dfs找到所有路径，值得注意的地方，开始我打算用一个动态数组存储经过的点，但是发现当有递归发生时，
归到分叉处时因为数组已经改变，所以很难处理，除非说新建一个新的动态数组，两个数组分别处理，
但是显然有更好的处理手段，所以这里我将动态数组改为字符串，走多少点，将点加到字符串上，
一开始我担心归到分叉处时字符串已经改变，会导致出错，但是显然多虑，因为当字符串+字符串时
在内存中字符串指针指向的已经是另外一个新字符串的地址，所以我这里的两次使用src+“-》”是完全，没
问题的

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
    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<String> result=new ArrayList<>();
        findAll(root, new String(), result);
        return result;
    }
    public void findAll(TreeNode node, String src,List<String> result){
        if (node.left == null && node.right == null){
            result.add(src+node.val);
            return;
        }
        if (node.left != null) {
            findAll(node.left, src+node.val+"->", result);
        }
        if (node.right != null) {
            findAll(node.right, src+node.val+"->", result);
        }
    }
}
```