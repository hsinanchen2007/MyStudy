### 解题思路
1. 定义一个队列存储节点及其深度，初始时队列只有一个元素`{root，0}`，定义备选右视图元素，初始为树根的值
2. 弹出队首元素，若已经进入了下一层（通过判断深度），则将上一层的最后那个右视图备选元素加入到结果集`ans`中
3. 循环执行步骤`2.`，直到队列为空，结果集`ans`即为所求

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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int>> tq;
        tq.push({root, 0});
        int tmp = 0;
        int cur = root->val;
        while(!tq.empty()){
            auto pr = tq.front(); tq.pop();
            TreeNode *root = pr.first;
            int h = pr.second;
            // 进入了树的下一层
            if(h > tmp){
                tmp = h;
                ans.push_back(cur);
            }
            cur = root->val;
            if(root->left) tq.push({root->left, h+1});
            if(root->right) tq.push({root->right, h+1});
        }
        // 加入最后一层的最后一个元素
        ans.push_back(cur);
        return ans;
    }
};
```