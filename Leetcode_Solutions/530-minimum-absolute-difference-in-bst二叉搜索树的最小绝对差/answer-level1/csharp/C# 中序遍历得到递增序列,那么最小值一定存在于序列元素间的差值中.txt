### 解题思路

##### 1. 题目概述：树中任意两节点差值的最小值

##### 2. 思路：
   - 特征：这是一颗二叉搜索树,若中序遍历,得到的结果就会是一个递增的序列;那么序列相邻元素的值就存在最小的可能性了;
   - 方案：递归,中序遍历,全局变量记录上一个值,以及目前得到的最小差值;
   - 结果：遍历一轮以后的结果

##### 3. 知识点：树 中序遍历 递归

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(h)


### 代码

```csharp解一 []
public class Solution {
        public int GetMinimumDifference(TreeNode root)
        {
            m_re = int.MaxValue;
            m_preNode = null;
            MidSearch(root);
            return m_re;
        }

        private int m_re;
        private TreeNode m_preNode;

        private void MidSearch(TreeNode root)
        {
            if (root == null) return;

            MidSearch(root.left);

            if (m_preNode != null)
                m_re = Math.Min(m_re, root.val - m_preNode.val);

            m_preNode = root;

            MidSearch(root.right);
        }
}
```
```csharp解二 []
public class Solution {
        public int GetMinimumDifference(TreeNode root)
        {
            m_min = int.MaxValue;
            m_preValue = int.MinValue / 4;
            LeftRootRightRecursive(root);
            return m_min;
        }

        private int m_min;
        private int m_preValue;

        private void LeftRootRightRecursive(TreeNode root)
        {
            if (root == null) return;

            LeftRootRightRecursive(root.left);

            m_min = Math.Min(m_min, root.val - m_preValue);
            m_preValue = root.val;

            LeftRootRightRecursive(root.right);
        }
}
```