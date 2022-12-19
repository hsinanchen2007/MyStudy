### 解题思路
此处撰写解题思路
我的思路：
    既然是看数量，那么我们将临时变量定义在外边，方法体中用
前序遍历的方式递归，然后临时变量累加起来！
最后返回的就是这个变量！
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
    int len=0;
    public int countNodes(TreeNode root) {
        if(root==null){
            return len;
        }
        len++;
        if(root.left!=null)
        countNodes(root.left);
        if(root.right!=null)
        countNodes(root.right);
        return len;
    }
}
```