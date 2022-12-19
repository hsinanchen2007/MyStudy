### 解题思路
这道题解题只需要三步：
1、递归求出最大深度;
2、利用最大深度算出二维数组应该多大，2^n-1;
3、递归求解，入参传递进入begin和end的index,每次depth下降时，对应的左右子树节点数值应该填写在对应的(begin+end)/2 的左右侧;

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
    vector<vector<string>> result;
    vector<vector<string>> printTree(TreeNode* root) {
        vector<string> vec;
        int depth = getHigh(root);
        int width = pow(2,depth) - 1;
        for (int i = 0; i < width; i++) {
            vec.push_back("");
        }
        for (int j = 0; j < depth; j++) {
            result.push_back(vec);
        }
        dfs(root, 0, 0, width);
        return result;
    }

    void dfs(TreeNode* root, int depth, int begin, int end) {
        if (root == nullptr) {
            return;
        } else {
            result[depth][(begin + end) / 2] = to_string(root->val);
        }
        dfs(root->left, depth + 1, begin, (begin + end) / 2);
        dfs(root->right, depth + 1, (begin + end) / 2, end);
        return ;
    }

    int getHigh(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(getHigh(root->left),getHigh(root->right));
    }
};
```