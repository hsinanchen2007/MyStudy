 这题是要把一个已经按升序排序好的数组转换成一个高度平衡的二叉树。

 首先的想法肯定是用递归来做。先找到数组中间的值作为根节点的值，然后根节点的左侧建立左子树，右侧建立右子树。

AC代码：
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
    TreeNode* SATB(TreeNode* root,vector<int>&nums, int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        root=new TreeNode(nums[mid]);
        root->left=SATB(root->left,nums,start,mid-1);
        root->right=SATB(root->right,nums,mid+1,end);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root;
        root=SATB(root,nums,0,nums.size()-1);
        return root;
    }
    
};
```