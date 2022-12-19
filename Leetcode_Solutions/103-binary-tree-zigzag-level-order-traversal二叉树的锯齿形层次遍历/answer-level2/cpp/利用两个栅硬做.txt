### 解题思路
两个栅硬做，内存超过5%

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> re;
        if (NULL == root) return re;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        bool fsm = true;
        while (!stk1.empty() || !stk2.empty()) {
            vector<int> layer;
            if (fsm) {
                while (!stk1.empty()) {
                    if (stk1.top() != NULL) {
                        layer.push_back(stk1.top()->val);
                        stk2.push(stk1.top()->left);
                        stk2.push(stk1.top()->right);
                    }
                    stk1.pop();
                }
            }
            else {
                while (!stk2.empty()) {
                    if (stk2.top() != NULL) {
                        layer.push_back(stk2.top()->val);
                        stk1.push(stk2.top()->right);
                        stk1.push(stk2.top()->left);
                    }
                    stk2.pop();
                }
            }
            fsm = !fsm;
            if (!layer.empty())
                re.push_back(layer);
        }
        return re;
    }
};
```