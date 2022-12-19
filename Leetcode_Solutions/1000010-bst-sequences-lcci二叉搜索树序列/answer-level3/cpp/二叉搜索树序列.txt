### 解题思路
1.根据题目意思,根节点肯定是第一个输入的.
2.当根节点确定后，做死的往做左子树乱搞,都不会影响右子树，同理右子树也是如此.
3.那么可以将左右子树看成子问题。
4.怎么合并，只要左右子数列表相对本身顺序不变，怎么插都行。

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
    void Combine(vector<int> &left,vector<int> &right,vector<int > &temp,vector<vector<int> > &res,int l,int r){
        if(l >= left.size() && r>=right.size()) {
            res.emplace_back(temp);
            return ;
        }
        if(l<left.size()){
            temp.emplace_back(left[l]);
            Combine(left,right,temp,res,l+1,r);
            temp.pop_back();
        }
        if(r<right.size()){
            temp.emplace_back(right[r]);
            Combine(left,right,temp,res,l,r+1);
            temp.pop_back();
        }
    }
    vector<vector<int> > GetResult(TreeNode *root){
        if(root == nullptr) return {};
        vector<vector<int> > left = GetResult(root->left);
        vector<vector<int> > right = GetResult(root->right);
        if(left.empty() && right.empty()) return {{root->val}};
        else if(left.empty()){
            for(int i = 0;i<right.size();++i){
                right[i].insert(right[i].begin(),root->val);
            }
            return right;
        }else if(right.empty()){
            for(int i = 0;i<left.size();++i){
                left[i].insert(left[i].begin(),root->val);
            }
            return left;
        }
        vector<vector<int> > res;
        vector<int> temp;
        int cur = 0;
        for(int i = 0;i<left.size();++i){
            for(int j = 0;j<right.size();++j){
                temp.clear();
                temp.emplace_back(root->val);
                Combine(left[i],right[j],temp,res,0,0);
            }
        }
        return res;
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
        static auto speedup = [](){ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();
        if(root== nullptr) return {{}};
        return GetResult(root);
    }
};
```