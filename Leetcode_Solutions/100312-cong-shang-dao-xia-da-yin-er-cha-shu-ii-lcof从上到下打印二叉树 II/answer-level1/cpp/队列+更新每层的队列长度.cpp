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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> res;
        queue<TreeNode *> qTree;
        qTree.push(root);  //第一个入队的是根节点
        while(true)
        {
            int qLength = qTree.size();  //每一层的队列长度
            if(qLength == 0)break;  //当队列长度为0即终止
            vector<int> temp;  //用于存放当前层的数据
            while(qLength--)  //当前层的队列长度不为0
            {
                TreeNode *node = qTree.front();
                if(node)
                {
                    temp.push_back(node->val);
                    if(node->left)qTree.push(node->left);  //入队前判空，确保temp不会是空列表
                    if(node->right)qTree.push(node->right);  //入队前判空
                }
                qTree.pop();  //当前层的队列出队
            }
            //当前层遍历完毕
            res.push_back(temp);
        }
        return res;
    }
};
```