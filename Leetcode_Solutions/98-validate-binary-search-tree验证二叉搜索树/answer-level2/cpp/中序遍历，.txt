### 解题思路
二叉搜索树：左<中<右。  
按照中序遍历，把值按照左中右的次序压入，
有左就左，压，有右就右.
最后判断数组是否依次增大。

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
    // 执行用时 :12 ms, 在所有 C++ 提交中击败了92.26% 的用户
    // 内存消耗 :18.5 MB, 在所有 C++ 提交中击败了100.00%的用户
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        if(!root->left&&!root->right) return true;
        vector<int> temp;//用数组存储中间量
        isValidBSTCore(root, temp);
        for(int i = 1;i<temp.size();++i){
            if(temp[i]<=temp[i-1]) return false;//若不是依次递增的就为false
        }
        return true;
    }

    void isValidBSTCore(TreeNode* root, vector<int>& temp){//中序遍历
        if(root->left){
            isValidBSTCore(root->left, temp);//若左子树存在就一直递归。
        }
        temp.push_back(root->val);//左子树右子树都不存再压入，或者压完了左子树压当前值。

        if(root->right){
            isValidBSTCore(root->right, temp);//若右子树存在也一直递归。
        }
    }
};
```