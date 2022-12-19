### 解题思路

##### 1. 题目概述：反转二叉树的左右子树

##### 2. 思路：
   - ：反转指代的是节点指向的左右子树反转了
   - ：针对每个节点,它负责的事情就是交换自己的左右子树,每个节点面临的处理操作是一致的
   - ：以上符合递归的处理思想,可以使用此种实现方式来解题
   
##### 3. 知识点：递归 树 前序遍历

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(logn)


### 代码

```csharp []
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
        public TreeNode InvertTree(TreeNode root)
        {
            if (root == null) return root;

            var temp = root.left;
            root.left = root.right;
            root.right = temp;

            InvertTree(root.left);
            InvertTree(root.right);

            return root;
        }
}
```