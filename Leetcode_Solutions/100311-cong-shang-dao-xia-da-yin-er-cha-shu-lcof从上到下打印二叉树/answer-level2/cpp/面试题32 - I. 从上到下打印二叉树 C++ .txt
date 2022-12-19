### 解题思路
广度优先遍历

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;    // 用一个vector用来保存结果
        if(!root){
            // 空数直接返回一个空vector
            return res;
        }

        deque<TreeNode*> QTreeNode;     // 创建一个队列
        QTreeNode.push_back(root);      // 将root放进队列

        while(QTreeNode.size()){
            // 如果队列不为空，出队列
            TreeNode* pNode = QTreeNode.front();    // 取队首元素
            res.push_back(pNode->val);              // 将队首元素的值保存到vector中
            QTreeNode.pop_front();      // 出队

            if(pNode->left){
                // 左孩子不为空，则将左孩子加到队列
                QTreeNode.push_back(pNode->left);
            }
            if(pNode->right){
                // 右孩子不为空，则将右孩子加到队列
                QTreeNode.push_back(pNode->right);
            }
        }

        return res;
    }
};
```