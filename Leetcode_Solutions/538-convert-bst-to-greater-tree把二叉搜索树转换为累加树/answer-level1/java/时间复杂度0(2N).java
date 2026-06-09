### 解题思路
两次遍历
1. 一次算出所有的和totalSum， 
2. 另外一次先序遍历，totalSum减去已经遍历过的节点，就是剩余的和。与当前的节点的值相加就是值 

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
    int totalSum;

    public TreeNode convertBST(TreeNode root) {

        int sum = sum(root);
        totalSum = sum;
        changeValue(root);
        return root;
    }


    private void changeValue(TreeNode root) {

        if (root == null) {
            return;
        }

        changeValue(root.left);
        totalSum = totalSum -root.val;
        root.val = root.val + totalSum;
        changeValue(root.right);


    }

    private int sum(TreeNode root) {

        if (root == null) {
            return 0;
        }
        int sum = sum(root.left);
        sum += root.val;
        sum += sum(root.right);
        return sum;
    }
}
```