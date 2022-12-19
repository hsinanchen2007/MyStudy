### 解题思路
nextLevel 用来计数下一层节点的个数,leftNode表示当前层还没有被保存的个数

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
        vector<vector<int>> res;    // 存放最终结果
        vector<int> levelRes;       // 存放每层结果    
        if(!root){
            return res;
        }

        deque<TreeNode*> QTreeNode;     // 创建一个队列
        QTreeNode.push_back(root);      // 将root放进队列
        int nextLevel = 0;              // 用来计数下一层节点的个数
        int leftNode = 1;               // 当前层还没有被保存的个数

        while(QTreeNode.size()){
            // 如果队列不为空，出队列
            TreeNode* pNode = QTreeNode.front();    // 取队首元素
            levelRes.push_back(pNode->val); // 把出队节点放到当前层的vector
            QTreeNode.pop_front();          // 出队
            --leftNode;                     // 当前层还没有被保存的节点个数减一

            if(pNode->left){
                // 左孩子不为空，则将左孩子加到队列
                QTreeNode.push_back(pNode->left);
                ++nextLevel;
            }
            if(pNode->right){
                // 右孩子不为空，则将右孩子加到队列
                QTreeNode.push_back(pNode->right);
                ++nextLevel;
            }

            if(leftNode == 0){
                // 当前层的节点都保存到levelRes中了，那么将levelRes再push到res中
                res.push_back(levelRes);
                levelRes.clear();   // 清空当前层的levelRes,用来保存下一层
                leftNode = nextLevel;   // 下一层未保存节点数
                nextLevel = 0;      // 置空下一层的数量
            }
        }

        return res;
    }
};
```