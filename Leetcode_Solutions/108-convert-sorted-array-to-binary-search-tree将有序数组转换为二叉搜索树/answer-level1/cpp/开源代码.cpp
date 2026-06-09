### 解题思路


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

 #include<vector>
 using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
        return NULL;

        TreeNode* root=new TreeNode(nums[nums.size()/2]);
        vector<int>vec_l=vector<int>(nums.begin(),nums.begin()+nums.size()/2);
        vector<int>vec_r=vector<int>(nums.begin()+nums.size()/2+1,nums.end());

        root->left=sortedArrayToBST(vec_l);
        root->right=sortedArrayToBST(vec_r);
        return root;
    }
};
```