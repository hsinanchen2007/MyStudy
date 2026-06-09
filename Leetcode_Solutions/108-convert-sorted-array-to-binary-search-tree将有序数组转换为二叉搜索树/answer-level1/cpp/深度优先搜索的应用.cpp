### 解题思路
1、固定一个start和end变量，取mid作为root节点。
2、递归得到root的左子树root的右子树。
这道题可以仔细体会一下深度优先搜索

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
    TreeNode* DFS(vector<int>& nums, int start, int end){
        if(start == end){
            return NULL;
        }
        int mid = (start + end)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = DFS(nums, start, mid);
        root->right = DFS(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
};
```