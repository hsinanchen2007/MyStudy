### 解题思路
考虑每次选择数组[i,j]最中间的元素k=(i+j)/2作为根结点root，左右子数组[i,k-1]和[k+1,j]的根结点分别是原数组根root的左右孩子结点。

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
    TreeNode* creat(vector<int>& nums,int i,int j)
    {
        if(i>j)return NULL;
        int k=(i+j)/2;
        TreeNode* root=new TreeNode(nums[k]);
        if(i==j)return root;
        else
        {
            root->left=creat(nums,i,k-1);
            root->right=creat(nums,k+1,j);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return creat(nums,0,nums.size()-1);
    }
};
```