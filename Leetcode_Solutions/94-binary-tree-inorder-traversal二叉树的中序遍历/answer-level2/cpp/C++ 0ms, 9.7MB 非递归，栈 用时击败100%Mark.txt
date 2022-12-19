### 解题思路
栈，其实就是将纵向深入的递归横向展开。
中序遍历：左节点-根节点-右节点
此题的递归算法思路简单清晰，那么转换到栈的层面上，需要支持的就是以下两个操作：
**1、不断寻找当前节点的左节点，并将当前节点压入栈中**
**2、到达叶节点后回溯，将根节点存入答案数组中，如果当前节点存在右节点，则进入右节点，重复1**
至于为什么使用 vector 而没用 stack，因为该题只需要支持“出栈”和“入栈”两个操作即可，vector 完全可以胜任，并能较继承自其的 stack 类型有常数级别的速度差异

![image.png](https://pic.leetcode-cn.com/3f656863b8aedf4383ee190af80f2f13e37f030c1583306eba8eeeeb08dc503b-image.png)

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
    vector<int> ans; // 答案数组
    vector<TreeNode*> st; // vector 模拟栈
    vector<int> inorderTraversal(TreeNode* root) {
        // 特殊情况处理
        if(root == NULL) return ans;
        st.push_back(root);
        // 对根节点实现操作 1
        while(root -> left != NULL)
        {
            root = root -> left;
            st.push_back(root);
        }
        while(st.size() > 0)
        {
            // 弹出栈顶根节点
            root = st[st.size() - 1];
            ans.push_back(root -> val);
            st.pop_back();
            // 如果当前根节点存在右节点
            if(root -> right != NULL)
            {
                // 进入右节点
                root = root -> right;
                st.push_back(root);
                // 重复操作 1
                while(root -> left != NULL)
                {
                    root = root -> left;
                    st.push_back(root);
                }
            }
        }
        return ans;
    }
};
```