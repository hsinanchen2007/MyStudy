## 思路
设置三个变量：
- level：标记当前层次，用于锯齿输出
- nextLevel：记录下一层元素个数
- toDeleted：记录当前层还没有访问的元素个数

首先头节点入队列
while (队列不为空)
  - 访问队头元素
  - 左节点不为空则入队，同时增加下一层元素个数
  - 右节点不为空则入队，同时增加下一层元素个数
  - 将当前层元素访问vector中，然后从队列弹出，递减toDeleted
  - if (当前层没有元素)
    - 更当前层元素为下一层元素个数，并重置下一层元素个数，递增层数 

### 代码
```c++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;        
        if (root == nullptr) return res;
        queue<TreeNode*> que;   
        vector<int> tmp;     
        int level = 1, nextLevel = 0, toDeleted = 1;
        que.push(root);
        while (!que.empty()) {
            TreeNode *cur = que.front();
            if (cur->left != nullptr) {
                que.push(cur->left);
                ++nextLevel;
            }
            if (cur->right != nullptr) {
                que.push(cur->right);
                ++nextLevel;
            }
            tmp.push_back(cur->val);
            que.pop();
            --toDeleted;
            if (toDeleted == 0) {
                toDeleted = nextLevel;
                nextLevel = 0;
                if (level % 2 == 0) {
                    reverse(tmp.begin(), tmp.end());
                }
                ++level;
                res.push_back(tmp);
                tmp.clear();                
            }
        }
        return res;
    }
};
```
