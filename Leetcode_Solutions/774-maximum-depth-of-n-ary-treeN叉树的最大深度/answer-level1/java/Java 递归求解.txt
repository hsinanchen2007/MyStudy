已经战胜 99.03 % 的 java 提交记录

在遍历的同时，根据我们传入的N叉树标识`depth`来不断的对最深的层数进行判断，每次都取其最大的`depth`。

```
class Solution {
    int count = 0;
    public int maxDepth(Node root) {
        search(root, 1);
        return count;
    }
    
    private void search(Node root, int depth) {
        // 如果已经走到了叶子节点，则返回上个递归函数
        if (root == null) return;

        // 动态的取当前遍历过的最大的N叉树深度
        count = Math.max(count, depth);
        // 遍历所有的子节点做相应的操作

        for (Node node : root.children) {
            search(node, depth + 1);
        }
    }
}
```