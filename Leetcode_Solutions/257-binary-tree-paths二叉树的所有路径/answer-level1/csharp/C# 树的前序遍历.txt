### 解题思路

##### 1. 题目概述：二叉树的所有路径

##### 2. 思路：
   - ：遍历到叶子节点的时候,路径就可以输出了,任务其实就完成了,比较明显的树的前序遍历的特征
   - ：对于每一个节点,如果自己是空,那么说明该输出路径了,否则把自己节点上的值,加入到数字列表中,继续深入到它的下一级
   - ：当所有的路径都遍历完以后,收集到的输出结果,就是题目所求的解了
   
##### 3. 知识点：树 前序遍历 递归

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(h) 即与树的高度有关


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
        public IList<string> BinaryTreePaths(TreeNode root)
        {

            m_list = new List<string>();
            Recursive(root, new List<int>());

            return m_list;
        }

        private IList<string> m_list;

        private void Recursive(TreeNode root, List<int> numList)
        {
            if (root == null) return;

            numList.Add(root.val);

            if(root.left == null && root.right == null)
            {
                m_list.Add(string.Join("->", numList));
            }
            else
            {
                Recursive(root.left, numList);
                Recursive(root.right, numList);
            }

            numList.RemoveAt(numList.Count - 1);
        }
}
```