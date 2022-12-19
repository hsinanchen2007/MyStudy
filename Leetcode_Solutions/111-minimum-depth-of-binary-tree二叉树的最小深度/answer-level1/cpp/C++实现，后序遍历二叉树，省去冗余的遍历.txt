### 解题思路
1.空节点
2.叶子节点
3.根节点
4.左邻居为叶子节点的当前节点（没必要遍历了），这个是重点

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
    int minDepth(TreeNode* root) {
        TreeNode *pre,*tmp;
        stack<TreeNode*> st;
        pre = NULL;
        int minDep = 0;
        if(!root){
            return minDep;
        }
        st.push(root);
        while(!st.empty()){
            tmp = st.top();
            if(!tmp){     //空节点
                st.pop();
                continue;
            }
            if(!tmp->left && !tmp->right){   //叶子
                st.pop();
                tmp->val = 1;
                pre = tmp;
                continue;
            }
            if(pre && (tmp->right == pre || tmp->left == pre)){     //根节点遍历
                st.pop();
                if(!tmp->left){
                    tmp->val = tmp->right->val + 1;
                }else if(!tmp->right){
                    tmp->val = tmp->left->val + 1;
                }else{
                    tmp->val = min(tmp->left->val,tmp->right->val) + 1;
                }
                pre = tmp;
                continue;
            }
            if(pre && pre->val == 1){     //左邻居为叶子节点，则不遍历当前节点，直接出栈
                st.pop();
                tmp->val = 1;
                pre = tmp;
                continue;
            }
            
            st.push(tmp->right);
            st.push(tmp->left);
        }
        return pre->val;
    }
};
```