### 4ms

#### 遍历顺序

**前序遍历**:根-左-右
**后序遍历**:左-右-根

**反后序遍历**:根右左

#### 定义两个栈

- stack1，模仿前序遍历的实现“反后序遍历”
- stack2，保存stack1的pop元素


```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root==nullptr) return res;
        std::stack<TreeNode* > stack1;
        std::stack<TreeNode *> stack2;
        stack1.push(root);
        while(!stack1.empty()){
            TreeNode* cur=stack1.top();
            stack1.pop();
            stack2.push(cur);
            if(cur->left){
                stack1.push(cur->left);
            }
            if(cur->right){
                stack1.push(cur->right);
            }
        }
        while(!stack2.empty()){
            TreeNode* node=stack2.top();
            stack2.pop();
            res.push_back(node->val);
        }
        return res;
    }
};
```
