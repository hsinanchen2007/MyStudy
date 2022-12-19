### 解题思路
此处撰写解题思路

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
        // if(root==NULL) return true;
        // vector<int> num;
        // midsearch(root,num);
        // for(int i=0;i<num.size()-1;i++){
        //     if(num[i]>=num[i+1]){
        //         return false;
        //     }
        // }
        // return true;
        return dfs(root,LONG_MIN,LONG_MAX);
    }

//递归判断左右子树，注意最小最大值
    bool dfs(TreeNode* root,long low,long hight){
        if(root == NULL) return true;
        if(low >=  root->val || hight <= root->val){
            return false;
        }
        if(!dfs(root->left,low,root->val)) return false;
        if(!dfs(root->right,root->val,hight)) return false;
        return true;
    }
//中序遍历，然后看数组是否有序
    void midsearch(TreeNode* root,vector<int> &num){
        if(root ==NULL) return ;
        midsearch(root->left,num);
        num.push_back(root->val);
        midsearch(root->right,num);
    }
};
```