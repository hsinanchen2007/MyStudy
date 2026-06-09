### 解题思路

##### 1. 题目概述：另一个数的子树

##### 2. 思路：
   - 特征：在一个树中,是否能找到另一颗树;
   - 方案：BFS 的方式遍历主树;DFS 的方式判断是否和子树一致;
   - 结果：只要找到一个满足条件的,那么就 OK

##### 3. 知识点：BFS DFS

##### 4. 复杂度分析: 
   - 时间复杂度：O(m*n)
   - 空间复杂度：O(m+h)


### 代码

```csharp []
public class Solution {
        public bool IsSubtree(TreeNode s, TreeNode t)
        {
            var queue = new Queue<TreeNode>();
            queue.Enqueue(s);
            while (queue.Any())
            {
                var curNode = queue.Dequeue();

                if (Recursive(curNode, t))
                    return true;

                if (curNode.left != null)
                    queue.Enqueue(curNode.left);
                if (curNode.right != null)
                    queue.Enqueue(curNode.right);
            }

            return false;
        }

        private bool Recursive(TreeNode s1, TreeNode t1)
        {
            if (s1 == null && t1 == null) return true;
            if (s1 == null || t1 == null || s1.val != t1.val) return false;

            return Recursive(s1.left, t1.left) && Recursive(s1.right, t1.right);
        }
}
```