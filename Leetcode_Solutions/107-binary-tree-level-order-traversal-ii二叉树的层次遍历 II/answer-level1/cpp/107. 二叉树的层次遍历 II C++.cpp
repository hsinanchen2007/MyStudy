### 解题思路
1.类似深度遍历，将自己的元素的内容存入自己对应的层数。
2.根据题目要求逆序返回层序遍历的结果。

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
    void levelorder(TreeNode* node, int level, vector<vector<int> >& res){
        if(!node) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorder(node->left,level + 1,res);
        if(node->right) levelorder(node->right,level + 1,res);
    }

    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        levelorder(root,0,res);
        return vector<vector<int> >(res.rbegin(),res.rend());
    }
};
```