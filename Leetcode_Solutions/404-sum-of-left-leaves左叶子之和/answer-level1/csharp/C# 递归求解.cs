### 解题思路

##### 1. 题目概述：左叶子之和

##### 2. 思路：
   - 特征：给定一个颗树,要知道所有的左叶子的和
   - 方案：遍历一个颗树,使用递归比较简洁,但是下一个节点并不知道自己到底是左节点还是右节点,因此有必要把这一信息也传递下去,然后只汇总左节点上的值
   - 结果：当遍历完整棵树以后,汇总得到值,就是所求的解

##### 3. 知识点：树 递归

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(h) h 表示树的高度


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
        public int SumOfLeftLeaves(TreeNode root)
        {
            m_totalInt = 0;
            Recursive(root, false);

            return m_totalInt;
        }

        private int m_totalInt;

        private void Recursive(TreeNode root, bool isLeft)
        {
            if (root == null) return;

            if (root.left == null && root.right == null)
            {
                if (isLeft)
                    m_totalInt += root.val;
            }
            else
            {
                Recursive(root.left, true);
                Recursive(root.right, false);
            }
        }
}
```