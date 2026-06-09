### 解题思路
层序遍历

两个判断 排除非完全二叉树

### 代码

```cpp

class Solution {
public:
bool isCompleteTree(TreeNode* root) {

    if (!root)
        return true;

    queue<TreeNode*> q;
    q.push(root);

    bool only_left_or_none = false;

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        if (!node->left && node->right) //仅有右子节点，无左子节点
            return false;

        if (only_left_or_none) //前面出现过只有左子节点 或 左右子节点都没有的
        {
            if (node->left || node->right) //当前节点必须是叶子节点
                return false;
        }

        if ((node->left && !node->right) || (!node->left && !node->right)) //只有左子节点 或 左右子节点都没有
        {
            only_left_or_none = true;
        }
            
        if (node->left)
        {
            q.push(node->left);
        }

        if (node->right)
        {
            q.push(node->right);
        }
    }

    return true;
}
};
```