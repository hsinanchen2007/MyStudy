### 解题思路
二叉搜索树的根是有序数组的中间那个元素
有序数组左右部分为左右子树，他们的根也是对应得中间元素
所以递归二分法

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
    TreeNode* helper(vector<int>& nums, int left,int right){
        if(left>right) return 0;
        int mid=(left+right)>>1;
        TreeNode* node=new TreeNode(nums[mid]);//创节点
        node->left=helper(nums,left,mid-1);//左子树
        node->right=helper(nums,mid+1,right);//柚子树
        return node;//返回根节点
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return 0;
        return helper(nums,0,nums.size()-1);
    }
};
```