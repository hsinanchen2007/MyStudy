### 解题思路
堆栈代替中序递归遍历

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> data;
        // 空数也是二叉搜索树
        if(!root) return true;

        // 以此中序遍历整个二叉树
        while(!stk.empty() || root) {
            // 左树一直压栈
            while(root) {
                stk.push(root);
                root = root->left;
            }
            // 取出栈顶，开始运算
            root = stk.top();
            stk.pop();
            data.push_back(root->val);

            // 保存之前已经遍历的节点，如果当前节点不满足情况直接返回
            if(data.size() > 1) {
                if(data[data.size()-2] >= data[data.size()-1]) return false;
            }
            // 当前的右子树准备入栈（如果有）
            root = root->right;
        }
        return true;
    }
};
```