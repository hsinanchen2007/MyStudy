重点在于既要保证每一层输入数组的是最右边的，也要保证所有层都会有元素输入；从右子树开始遍历，然后根据当前数组中的元素个数与当前层数判断当前节点是否需要输入。
这种方式时间效率还比较高。

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
    void helper(vector<int>&vec,TreeNode* root,int h)
    {
        if(root==nullptr)return;
        if(h>vec.size())
        vec.push_back(root->val);
        helper(vec, root->right, h+1);
        helper(vec, root->left, h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        helper(vec,root,1);
        return vec;

    }
};
```