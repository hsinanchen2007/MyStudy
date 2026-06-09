### 解题思路
一个有序数组来创建一个平衡二叉搜索树，直接二分。把中间的点作为根节点。再依次递归，
这里求中间的数用位运算快很多。




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
    // 执行用时 :28 ms, 在所有 C++ 提交中击败了27.23% 的用户
    // 内存消耗 :23.1 MB, 在所有 C++ 提交中击败了18.47%的用户
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        if(nums.size()==1) return new TreeNode(nums[0]);
        return sortedArrayToBSTCore(nums, 0, nums.size()-1);
    
    }
    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int start, int end){
        if(start>end){//若start>end 返回空指针。
            return nullptr;
        }
        int mid = (end+start)>>1;//比除法快很多、
        TreeNode* root = new TreeNode(nums[mid]);//取中间数为父节点、再依次递归左右子树。
        root->left = sortedArrayToBSTCore(nums, start, mid-1);
        root->right = sortedArrayToBSTCore(nums, mid+1, end);
        return root;
    }


};
```