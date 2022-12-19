### 解题思路
这个题啊，我看了好多遍都没有很明白题意。
心想这个把所有节点遍历一遍，一排序不久完了吗
试了试还真是这样，效率还可以，在尝试下递归方法把

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
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        sort(ret.begin(),ret.end());
        for(auto num:ret)
        if(num>ret[0]) return num;
        return -1;
    }
private:
    void dfs(TreeNode* root)
    {
        if(root==NULL) return;
        ret.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
private:
    vector<int> ret;
};
```