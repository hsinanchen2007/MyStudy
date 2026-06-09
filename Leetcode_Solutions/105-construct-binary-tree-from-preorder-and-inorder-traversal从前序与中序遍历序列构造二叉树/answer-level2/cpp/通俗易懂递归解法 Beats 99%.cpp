### 解题思路
先序遍历确定访问顺序，中序遍历确定左右子树信息

### 代码
基础代码：
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx = 0;
        return helper(preorder, inorder, 0, inorder.size()-1,pre_idx);
    }

    // C++中函数无法嵌套定义
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& pre_idx){
    if(start > end) return NULL;
    int root_val = preorder[pre_idx];
    pre_idx++;
    TreeNode* root = new TreeNode(root_val);
    int idx = find(inorder.begin(), inorder.end(), root_val) - inorder.begin();
    root->left = helper(preorder, inorder, start, idx-1, pre_idx);
    root->right = helper(preorder, inorder, idx+1, end, pre_idx);
    return root;
    }
};
```
借助于哈希表用空间换时间：
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inor_dict;
        for(int i=0; i<inorder.size(); i++)
            inor_dict[inorder[i]] = i;
        int pre_idx = 0;
        return helper(preorder, inor_dict, 0, inorder.size()-1,pre_idx);
    }

    // C++中函数无法嵌套定义
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& inor_dict, int start, int end, int& pre_idx){
    if(start > end) return NULL;
    int root_val = preorder[pre_idx];
    pre_idx++;
    TreeNode* root = new TreeNode(root_val);
    int idx = inor_dict[root_val];
    root->left = helper(preorder, inor_dict, start, idx-1, pre_idx);
    root->right = helper(preorder, inor_dict, idx+1, end, pre_idx);
    return root;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ada0eaf499ad9e7e794b012fcf3d67ed05725eed425976ed065487c319f709a8-image.png)
