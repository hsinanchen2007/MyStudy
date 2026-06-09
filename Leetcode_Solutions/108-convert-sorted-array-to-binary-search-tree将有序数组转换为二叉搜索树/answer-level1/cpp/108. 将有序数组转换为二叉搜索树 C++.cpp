### 解题思路
1.一个二叉搜索树的中序遍历即是一个有序数组，所以只需要将有序数组逆变换就可以转换成一个二叉搜索树。
2.先找数组中间元素将其作为根结点，则其左半部分数组则是左子树，右半部分数组则是右子树。
3.不断循环步骤2即可完成二叉搜索树。

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
    TreeNode* DFS(vector<int>& nums, int start,int end){
        if(start == end){
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = DFS(nums,start,mid);
        root->right = DFS(nums,mid + 1,end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums,0,nums.size());
    }
};
```