### 解题思路
此处撰写解题思路
使用一个栈保存有左右子节点的节点。
我的想法是：每一次循环都从栈中获取栈顶元素。接着判断当前节点是否有左子节点，
有则把此节点的左子节点压入栈顶，再把当前节点的left指针置为NULL，防止下一次从栈中再获取到
此元素时，再次把此元素的左子节点压入栈中，导致死循环。最后进入下一个循环。
如果没有，判断当前节点是否有右子节点，有则输出当前节点值，从栈中移除此元素，
接着压入当前节点的右子节点。这里和操作左子节点一样，置right指针为NULL，进入下一个循环。
如果当前节点为叶子节点，输出此节点的值，从栈中移除此元素。
直到栈为空。遍历结束。


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        TreeNode* cur;
        stack<TreeNode*> st;
        if(root == NULL)
            return out;
        st.push(root);
        while(!st.empty())
        {
            cur = st.top();
           
            if(cur->left != NULL)
            {
                st.push(cur->left);
                cur->left = NULL;
            }else if(cur->right != NULL)
            {
                out.push_back(cur->val);
                st.pop();
                st.push(cur->right);
                cur->right = NULL;
            }
            else{
                out.push_back(cur->val);
                st.pop();
            }
        }
        return out;
    }
};
```