### 执行结果：
执行用时 :2 ms, 在所有 Java 提交中击败了99.71%的用户；
内存消耗 :37.4 MB, 在所有 Java 提交中击败了98.31%的用户。

### 解题思路
先序遍历二叉树，将当前节点的值加入字符串末尾，接着遍历子树；
```
    result.append(current.val);
```
加括号规则：当右子树不为空时，不管左子树是否为空，都需要加括号；右子树为空不加括号；当左右子树都为空时，不加括号。



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
    public StringBuilder result = new StringBuilder();
    public String tree2str(TreeNode t) {
        
        dfs(t);
        return new String(result);
    }

    public void dfs(TreeNode current){

        if(current == null) return;

        result.append(current.val);

        if(current.left == null && current.right == null)
            return;
        else{
            result.append("(");
            dfs(current.left);
            result.append(")");

            if(current.right != null){
                result.append("(");
                dfs(current.right);
                result.append(")");
            }
        }
    }
}
```