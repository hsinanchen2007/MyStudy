### 解题思路
此题类似于[113路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

###方法一：递归
使用DFS递归方法，每次遍历到叶子节点就向上返回一层，并修改tmp

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
    int sum = 0;
    int tmp = 0;
    public int sumNumbers(TreeNode root) {
        if(root == null) return;
        tmp = tmp * 10 + root.val;
        if(root.left == null && root.right == null){
            sum += tmp;
        }
        sumNumbers(root.left);
        sumNumbers(root.right);
        tmp = tmp / 10;  //回溯
        return sum;
    }

    

}
```