**分析：**
题目思路源于官方题解，每次选取右方元素作为节点。

**代码：**
```
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
    TreeNode* helper( vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        int p = (left + right) / 2;  
        //注意这里不能是 p % 2 == 1，不知道原因，猜测是到边界情况再加1，没有那个nums的值
        if((left + right)% 2 == 1){
            p++;
        }
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums, left, p-1);
        root->right = helper(nums, p+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
```
