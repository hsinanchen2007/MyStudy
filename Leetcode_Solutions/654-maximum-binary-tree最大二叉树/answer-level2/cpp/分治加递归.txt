因为题目说要找最大值作为根节点,然后根节点左边和右边又执行同样的操作 构建一棵树 第一反应就是分治算法,通过最大值分左右两部分,然后执行同样的操作就很容易想到递归 思路大概就这样直接上代码
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
        int get_max_index( vector<int>& nums, int left, int right ) {
          //找出最大值,创建根结点
          int index = left;
          for( int i = left; i <= right; ++i ) {
            if ( nums[i] > nums[index] ) {
              //更新index
              index = i;
            }
          }
          return index;
        }
        TreeNode* helper( vector<int>& nums, int left, int right ){
        if ( left > right ) {
            return NULL;
        }
        int index = get_max_index( nums, left, right );
        TreeNode* root = new TreeNode( nums[index] );
        //处理左子树
        root->left = helper( nums, left, index - 1 );
        //处理右子树
        root->right = helper( nums, index + 1, right );
        return root;
    
    }
    
    TreeNode* constructMaximumBinaryTree( vector<int>& nums ) {
        if ( nums.size() == 0 ) {
            return NULL;
        }
        //找出最大值,创建根结点
        int index = get_max_index( nums, 0, nums.size() - 1 );
        TreeNode* root = new TreeNode( nums[index] );
        //处理左子树
        root->left = helper( nums, 0, index - 1 );
        //处理右子树
        root->right = helper( nums, index + 1, nums.size() - 1 );
        return root;
    }
};