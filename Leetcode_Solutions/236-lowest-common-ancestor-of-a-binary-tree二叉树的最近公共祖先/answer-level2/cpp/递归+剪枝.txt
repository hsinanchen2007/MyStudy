### 解题思路
主要思路就是DFS。每个节点有一个计数器，记录其本身和子节点中有几个目标节点，如果是2个的话就可以考虑给结果赋值了。如何保证是最近的呢？让保存结果的指针初始化为NULL，在考虑赋值的时候若该指针为NULL，则为所求，否则就是其父节点，无需赋值。可以通过简单剪枝来避免无用的遍历。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &result) {
        if (!root || result) // 空节点或已找到最近公共祖先
            return 0;
        
        int current = 0;          // 初始化计数器
        if (root == p)             // 判断当前节点
            current++;
        if (root == q)
            current++;
        
        if (current != 2 && !result)          // p == q时，找到结果以后无需遍历其子节点
            current += f(root->left, p, q, result);
        if (current != 2 && !result)            // 左子树中已经包含了两个目标节点
            current += f(root->right, p, q, result);

        if (!result && current == 2)         // 判断是否为所求
            result = root;
        return current;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = NULL;
        f(root, p, q, result);
        return result;
    }
};
```