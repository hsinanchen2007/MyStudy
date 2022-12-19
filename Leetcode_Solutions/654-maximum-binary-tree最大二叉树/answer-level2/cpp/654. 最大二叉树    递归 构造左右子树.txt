### 解题思路
每次递归构造节点要找最大值
构造shu：左子树为节点的左边，柚子树为数组的右边
所以helper(nums,left,index-1);

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
    int max(vector<int>& nums,int left,int right){
        int max=nums[left];
        int index=left;
        for(int i=left+1;i<=right;i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        return index;
    }

    TreeNode* helper(vector<int>& nums,int left,int right){
        if(left>right) return NULL;
        int index=max(nums,left,right);
        TreeNode* head=new TreeNode(nums[index]);
        head->left=helper(nums,left,index-1);
        head->right=helper(nums,index+1,right);
        return head;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
```