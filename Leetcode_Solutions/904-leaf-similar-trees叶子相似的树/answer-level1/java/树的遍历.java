### 解题思路
此处撰写解题思路
找到叶子节点，直接递归，将节点保存为String类型，最后比较值
递归出口： root==null，直接返回String
递归操作： 如果左右节点为null，直接添加到String里
返回操作： 将左右节点的值加起来
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        String s1 = find(root1,"");
        String s2 = find(root2,"");
        return s1.equals(s2);
    }
    public String find(TreeNode root, String s){
        if(root == null)
            return s;
        if(root.left == null && root.right == null){
            s = s + root.val;
        }
        return find(root.left,s) + find(root.right,s);
    }
}
```