### 解题思路
借助于中序遍历，并将遍历结果放到列表（_items）中，同时定义并使用一个索引变量 _currentIndex，用于记录当前访问元素的位置。

在Next方法中，返回_currentIndex位置的元素，并将该变量的值增1；而在HasNext方法中，则判断它是否小于列表_items的长度。

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
public class BSTIterator {
    private int _currentIndex=0; // 访问元素的索引 
    private List<int> _items = new List<int>();
    public BSTIterator(TreeNode root) {
        if(root==null)
        {
            return;
        }

        InOrder(root,_items);
    }

    private void InOrder(TreeNode root, List<int> _items)
    {
        if(root == null) return;
        InOrder(root.left,_items);
        _items.Add(root.val);
        InOrder(root.right,_items);
    }
    
    /** @return the next smallest number */
    public int Next() {
        return _items[_currentIndex++];
    }
    
    /** @return whether we have a next smallest number */
    public bool HasNext() {
        return _currentIndex<_items.Count;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */
```