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
 #include<queue>
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<int> res;
        queue<TreeNode *> qTree;  //初始化队列
        qTree.push(root);  //初始队列为root
        int qLength = 1;  //初始队列只有一个元素root，长度为1
        while(qLength)
        {
            TreeNode *temp = qTree.front();
            if(temp)
            {
                res.push_back(temp->val);
                qTree.push(temp->left);  //左子树入队
                qTree.push(temp->right);  //右子树入队
            }
            qTree.pop();
            qLength = qTree.size();  //每次在最后更新队列长度
        }
        return res;
    }
};
```