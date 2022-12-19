### 解题思路
创建一个栈，用来存放待遍历的节点，算法如下：
1. 先把root压栈；
    2. 如果栈不为空，则把栈顶元素弹出并获取
    3. 如果弹出的元素不是空指针，那么把它的value加入结果ret，同时先压栈右节点，再压栈左节点。
    4. 如果为空，则跳过后面的步骤
5. 最后返回结果就可以了

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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> st;
        vector<int> ret;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node == nullptr) {
                continue;
            }
            ret.push_back(node->val);
            st.push(node->right);
            st.push(node->left);
        }
        return ret;
    }
};
```