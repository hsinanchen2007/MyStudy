### 解题思路

##### 1. 题目概述：路径总和

##### 2. 思路：
   - 特征：路径都是从上至下的,每个节点都可以作为起始点,或者终止点,只要路径和满足要求的话,就会被统计了
   - 方案：自上至下,会经过多个节点,每个节点都可以作为起始点/参与点,相当于是每个点都参与维护了到目前为止多个路径的汇总结果
   - 结果：每个节点都去判断一下,维护的汇总结果中,是否有满足要求的,有几个,就汇总几个
   - 其它：节点的值范围是 -1000000 ~ 1000000 节点总数是 1000,那么就是说,所有节点之和不会超过 1000 000 000,在整形的数据表示范围内

##### 3. 知识点：DFS

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(h) --> h 表示树的最大高度


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
        public int PathSum(TreeNode root, int sum)
        {
            m_count = 0;
            Dfs(root, sum, new List<int>());
            return m_count;
        }

        private int m_count;

        private void Dfs(TreeNode root, int sum, IList<int> sumResult)
        {
            if (root == null) return;

            var curValue = root.val;
            for (var i = 0; i < sumResult.Count; i++)
                sumResult[i] += curValue;
            sumResult.Add(curValue);

            foreach (var item in sumResult)
                if (item == sum) m_count++;

            Dfs(root.left, sum, sumResult);
            Dfs(root.right, sum, sumResult);

            for (var i = 0; i < sumResult.Count; i++)
                sumResult[i] -= curValue;
            sumResult.Remove(0);
        }
}
```