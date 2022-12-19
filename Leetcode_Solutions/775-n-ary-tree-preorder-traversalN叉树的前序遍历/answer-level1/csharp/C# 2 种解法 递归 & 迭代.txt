### 解题思路
迭代
时间复杂度:O(n)
空间复杂度 O(n)

### 代码

```csharp []
public class Solution {
        public IList<int> Preorder(Node root)
        {
            var forReturn = new List<int>();
            if (root == null) return forReturn;

            var stackTemp = new Stack<Node>();
            stackTemp.Push(root);
            while (stackTemp.Any())
            {
                var curNode = stackTemp.Pop();

                forReturn.Add(curNode.val);

                for (var i = curNode.children.Count - 1; i >= 0; i--)
                    stackTemp.Push(curNode.children[i]);
            }

            return forReturn;
        }
}
```

### 解题思路
递归
时间复杂度:O(n)
空间复杂度:O(h)

### 代码

```csharp []
public class Solution {
        public IList<int> Preorder1(Node root)
        {
            m_list = new List<int>();
            Dfs(root);
            return m_list;
        }

        private List<int> m_list;

        private void Dfs(Node root)
        {
            if (root == null) return;

            m_list.Add(root.val);

            foreach (var item in root.children)
                Dfs(item);
        }
}
```