### 解题思路
先看执行情况：
![image.png](https://pic.leetcode-cn.com/8a070f3a16ecb548212ce6d307bbd59353f8f5d87342c488a65706ae88ad7744-image.png)
执行用时有点长，但是可以在此基础上优化。
大体思路是获取根节点，递归的求解左右子树，终止条件是当子树的长度等于1时返回。

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
public TreeNode buildTree(int[] preOrder, int[] inOrder) {
        int length = preOrder.length;
        if (length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(preOrder[0]);
        if (length == 1) {
            return root;
        }
        int pointer = 0;
        while (inOrder[pointer] != preOrder[0]) {
            pointer ++;
        }
        
        int[] leftPreOrder = new int[pointer];
        int[] leftInOrder = new int[pointer];
        int[] rightPreOrder = new int[length - 1 - pointer];
        int[] rightInOrder = new int[length - 1 - pointer];
        for (int i = 0; i < leftInOrder.length; i ++) {
            leftInOrder[i] = inOrder[i];
        }
        for (int i = 0; i < rightInOrder.length; i ++) {
            rightInOrder[i] = inOrder[i + pointer + 1];
        }

        for (int i = 0; i < leftPreOrder.length; i ++) {
            leftPreOrder[i] = preOrder[i + 1];
        }
        for (int i = 0; i < rightPreOrder.length; i ++) {
            rightPreOrder[i] = preOrder[i + pointer + 1];
        }

        TreeNode left = buildTree(leftPreOrder, leftInOrder);
        TreeNode right = buildTree(rightPreOrder, rightInOrder);
        root.left = left;
        root.right = right;
        return root;
    }
}
```