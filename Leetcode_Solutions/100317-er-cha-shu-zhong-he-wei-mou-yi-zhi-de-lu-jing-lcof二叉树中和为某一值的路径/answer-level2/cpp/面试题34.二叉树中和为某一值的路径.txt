### 解题思路
核心思路：设置二维向量result存结果，一维向量path存当前递归路径，递归到某个节点，先将它加入path，凡是出现当前递归到的节点sum减到了0且为叶节点（无左孩子和右孩子），就将当前的path存入result，递归左右子树，递归结束后删除当前递归节点
执行用时 :28 ms, 在所有 C++ 提交中击败了21.98%的用户
内存消耗 :20 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    vector<vector<int>>result;
    vector<int>path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        recur(root,sum);
        return result;
    }
    void recur(TreeNode*root,int sum){
        if(root==NULL)return;
        int ex=sum-root->val;
        path.push_back(root->val);
        if(ex==0&&root->left==NULL&&root->right==NULL){
            result.push_back(path);
        }
        recur(root->left,ex);
        recur(root->right,ex);
        path.pop_back();
    }
};
```