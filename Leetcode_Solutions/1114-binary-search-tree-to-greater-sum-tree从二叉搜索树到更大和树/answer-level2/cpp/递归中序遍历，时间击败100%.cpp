### 解题思路
见函数中的注释。

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
    void inorderGet(TreeNode* root, vector<int> & values)
    {
        if(!root) return;
        if(root->left)  inorderGet(root->left, values);
        values.push_back(root->val);
        if(root->right) inorderGet(root->right, values);
    }
    void inorderAss(TreeNode* root, unordered_map<int, int> & newVals)
    {
        if(!root) return;
        if(root->left)  inorderAss(root->left, newVals);
        root->val = newVals[root->val];
        if(root->right) inorderAss(root->right, newVals);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        //中序遍历，得到顺序排列
        vector<int> values;
        inorderGet(root, values);
        //分别相加，得到各值对应的值
        unordered_map<int, int> newVals;
        int temp;
        newVals[values[values.size()-1]] = values[values.size()-1];
        for(int idx = values.size()-2; idx >= 0; --idx)
        //  本地g++编译 += 会返回结果的。。。这里似乎解析成了判断语句为0
        //  newVals[values[idx]] = (values[idx] += values[idx+1]);
        {
            temp = values[idx];
            values[idx] = values[idx] + values[idx+1];
            newVals[temp] = values[idx];
        }
        //赋值到结点上
        inorderAss(root, newVals);
        return root;
    }
};
```