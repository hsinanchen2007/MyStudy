### 解题思路
路径符合先序遍历的形式，于是我们采用先序遍历实现，偷懒一下，不想写非递归了，用个递归玩下了。

每个叶子就是一个路径，加入到list中即可，不是叶子节点的，进入左右子树递归即可，记得路径加上一个->，不难。

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
        List<String> res = new ArrayList<>();
        preOrderTree_257(root,"",res);
        return res;
    }

    private void preOrderTree_257(TreeNode node,String prev,List<String> res){
        if (node == null){
            return;
        }
        prev += node.val;
        if (node.left == null && node.right == null){
            res.add(prev);
        }else {
            prev += "->";
            preOrderTree_257(node.left,prev,res);
            preOrderTree_257(node.right,prev,res);
        }
    }
}
```