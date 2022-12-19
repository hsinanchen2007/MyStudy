### 解题思路
解法一 递归
二叉搜索树的中序遍历刚好可以输出一个升序数组。

根据中序遍历还原一颗树，又想到了 105 题 和 106 题，通过中序遍历+前序遍历或者中序遍历+后序遍历来还原一棵树。前序（后序）遍历的作用是提供根节点，然后根据根节点，递归的生成左右子树。

本题要求平衡二叉树，既然要做到平衡，我们只要把根节点选为数组的中点即可。

综上，和之前一样，找到了根节点，然后把数组一分为二，进入递归即可。注意这里的边界情况，包括左边界，不包括右边界。


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
    TreeNode* sortedArr(vector<int>& nums, int start, int end)
    {
        if(start == end)
            return NULL;
        int mid = start+(end-start)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArr(nums,start,mid);
        root->right = sortedArr(nums, mid+1,end);

        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArr(nums,0,nums.size());
    }
};
```