### 解题思路
此处撰写解题思路

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
    vector<int> number;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        number = nums;
        return helper(0,number.size()-1);
    }
    //创建根节点
    //通过递归实现创建整个树
     TreeNode* helper(int left,int right)
     {
         //递归结束条件
         if(left>right) return NULL;
         TreeNode* node = new TreeNode(-1);
         int p = (left+right)/2;
         node->val =number[p];
         node->left = helper(left,p-1);
         node->right = helper(p+1,right);
         return node;
     }
};
```