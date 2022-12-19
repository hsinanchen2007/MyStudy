## DFS
从右到左深入递归，比较层级替换最左值
```java 
class Solution 
{
    int maxLevel;
    int leftVal;
    public int findBottomLeftValue(TreeNode root) 
    {
        maxLevel = 0;
        leftVal = 0;
        findLeftValue(root, 0);
        return leftVal;
    }

    private void findLeftValue(TreeNode root, int level)
    {
        if (root == null)
            return ;
        if (level >= maxLevel)
        {
            maxLevel = level;
            leftVal = root.val;
        }
        findLeftValue(root.right, level + 1);
        findLeftValue(root.left, level + 1);
    }
}
```
## BFS
从上至下迭代，每次从右开始入队，最后一个就是最左节点
```python
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        stack = list()
        stack.append(root)
        last = root
        while stack:
            last = stack.pop(0)
            if last.right:
                stack.append(last.right)
            if last.left:
                stack.append(last.left)
        return last.val
```


