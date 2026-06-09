![捕获.PNG](https://pic.leetcode-cn.com/82541502c8c555466a46ec9cc8a5aa5a7451e578009fa25fdea166e072daab79-%E6%8D%95%E8%8E%B7.PNG)

1、思路：详见code

2、复杂度分析
    时间：每个元素仅进、出栈一次，所以时间复杂是O(n);
    空间：最多存储二叉树的所有结点，所以复杂度是O(n));

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;  // 树为空则直接返回
        vector<int> each_level;  //依次存储每一层从左往右的结点值
        queue<TreeNode*>q;  // 队列，先进进出(FIFO)
        q.push(root);
        while(!q.empty()) {
            int size = q.size();  // 每层的结点数
            for(int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();  // 将现结点加入each_level
                each_level.push_back(curr->val);
                // 非空结点不计入答案，所以要判断现结点的左右结点是否为空
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();  //记得弹出之前的头结点
            }
            ans.push_back(each_level);  // 把每层的结点存入ans
            each_level.clear();  //  清除每层的结点，以便添加下一层的非空结点
        }
        return ans;

    }
};
```