### 解题思路
中序遍历放入数组，对递增数组进行双指针查找。

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
private:
 vector<int>res;
public:
    bool findTarget(TreeNode* root, int k) {
       if(root==NULL){
           return false;
       }
       dfs(root);
       int len=res.size();
       int left=0;
       int right=len-1;
       while(left<right){
           if(res[left]+res[right]<k){
               left++;
           }
           else if(res[left]+res[right]>k){
               right--;
           }
           else{
               return true;
           }
       }
       return false;
    }

    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
```