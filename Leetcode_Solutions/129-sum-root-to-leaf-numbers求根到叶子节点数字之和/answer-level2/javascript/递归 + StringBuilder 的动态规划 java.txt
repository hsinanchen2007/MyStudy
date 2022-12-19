### 解题思路
利用stringBuilder可以改变的特性，从根节点到叶子节点，全部记录下来，一旦到了叶子节点就将String转化为int累加起来

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

    int res;
    StringBuilder numStr = new StringBuilder();

    public int sumNumbers(TreeNode root) {
        if(root == null) return res;

        numStr.append(root.val);

        sumNumbers(root.left);
        sumNumbers(root.right);

        //判断是不是叶子节点，是就累加，不是就跳过
        if(root.left == null && root.right == null) {
            res += Integer.valueOf(numStr.toString());
        }

        numStr.deleteCharAt(numStr.length() - 1);

        return res;
    }
}
```