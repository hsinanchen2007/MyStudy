### 解题思路
![image.png](https://pic.leetcode-cn.com/af2f7ba242916c0f50d7cb59437ed5bca2888447ce3783d2e32a489db27d9287-image.png)

中序遍历二叉查找树生成一个排序的数组，对数组求第k大的元素

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
    int kthLargest(TreeNode* root, int k) {
        vector<int> ans;
        midorder(root,ans);
        for(int i=ans.size()-1;i>=0;i--){
            if(ans.size()-i==k)return ans[i];
        }
        return 0;
    }
    void midorder(TreeNode* root,vector<int>& res){
        if(root==NULL)return;
        TreeNode *cur=root;
        if(cur->left!=NULL)midorder(cur->left,res);
        res.push_back(cur->val);
        if(cur->right!=NULL)midorder(cur->right,res);
    }
};
```