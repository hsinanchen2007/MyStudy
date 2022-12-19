### 解题思路
定义一个深度，用于记录每次需要在vecvec<vector<int>>新建vector<int>或取什么位置的vector<int>插入值。
1.当前l<size,取size-l处的vector往里填
2.当前l>size，新建一个
3.由于，我的递归式不存在l>size+1及更大的情况，所以2正确。
然后就是常规的判断
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
    vector<vector<int>> result;
    vector<vector<int>> levelOrderBottom(TreeNode* root,int l=1) {
        if(!root)
            return result;
        if(result.size()<l)
        {
            vector<int> mid;
            mid.push_back(root->val);
            result.insert(result.begin(),mid);
        }
        else
            result[result.size()-l].push_back(root->val);
        levelOrderBottom(root->left,l+1);
        levelOrderBottom(root->right,l+1);
        return result;
    }
};
```