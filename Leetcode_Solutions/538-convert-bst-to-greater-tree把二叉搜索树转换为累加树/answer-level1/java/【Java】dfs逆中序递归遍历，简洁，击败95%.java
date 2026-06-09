# 思路
**dfs逆中序遍历**
## 递归函数的参数
- **node**：当前遍历到的节点
- **sum**：累加值
## 过程逻辑
- **退出条件**：当前遍历到的节点为空，返回sum值
- **过程是逆中序深度优先遍历**:
    1. 带着`sum`去遍历右子树，返回遍历后累加得到的`sum` 
    2. 将当前节点`node.val`和`sum`累加，使`node.val`符合题目要求
    3. 将`node.val`作为`sum`值带着去遍历左子树
- 完成当前层的逆中序遍历步骤后，将`sum`返回上一层
# 代码
```java[]
class Solution {
    public TreeNode convertBST(TreeNode root) {
        if (root != null) {
            dfs(root, 0);
        }
        return root;
    }

    private int dfs(TreeNode node, int sum) {
        if (node == null) {
            return sum;
        }
        
        sum = dfs(node.right, sum);
        
        node.val += sum;
        
        sum = dfs(node.left, node.val);
        
        return sum;
    }
}
```
