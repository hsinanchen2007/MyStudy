### 解题思路
1.定义一个 class MyTreeNode 继承 TreeNode，添加一个root字段表示当前节点的根节点
2.遍历一次二叉树，取出所有叶子节点 List<MyTreeNode> yz;
3.逆向比较叶子节点，输出结果
### 代码

```csharp
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
    
    public class MyTreeNode : TreeNode
    {
        // 当前节点的根节点
        public MyTreeNode root;

        public MyTreeNode(int x)
            : base(x) { }
    }

    public string SmallestFromLeaf(TreeNode root)
    {
        StringBuilder result = new StringBuilder();
        List<MyTreeNode> yz = new List<MyTreeNode>();
        getYz(new MyTreeNode(root.val)
        {
            left = root.left,
            right = root.right,
            root = null,
        }, yz);

        appenChar(result, yz);
        return result.ToString();
    }

    private void appenChar(StringBuilder result, List<MyTreeNode> yz)
    {
        if (yz.Count == 0)
            return;

        List<MyTreeNode> minis = new List<MyTreeNode>();
        int mini = yz[0].val;
        minis.Add(yz[0]);
        for (int i = 1; i < yz.Count(); i++)
        {
            var item = yz[i];
            if (item.val < mini)
            {
                minis.Clear();
                mini = item.val;
                minis.Add(item);
            }
            else if (item.val == mini)
            {
                minis.Add(item);
            }
        }

        result.Append((char)('a' + mini));

        if (minis.Any(x => x.root == null))
            return;

        appenChar(result, minis.Select(x => x.root).ToList());
    }

    private void getYz(MyTreeNode root, List<MyTreeNode> yz)
    {
        if (root.left == null && root.right == null)
        {
            yz.Add(root);
        }
        else
        {
            if (root.left != null)
            {
                getYz(new MyTreeNode(root.left.val)
                {
                    left = root.left.left,
                    right = root.left.right,
                    root = root,
                }, yz);
            }

            if (root.right != null)
            {
                getYz(new MyTreeNode(root.right.val)
                {
                    left = root.right.left,
                    right = root.right.right,
                    root = root,
                }, yz);
            }
        }
    }
}
```