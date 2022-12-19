用栈维护当前节点的祖先节点集合。
如果当前深度大于栈的长度，将多余的节点出栈，保证栈中只包含当前节点的祖先节点。
栈顶为当前节点的父节点。
如果父节点的左子树为空，则将当前值赋给左子树，否则赋值给右子树。
```
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
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> st;
        int i=findNum(S, 0);
        TreeNode* root = new TreeNode(atoi(S.substr(0, i).c_str()));
        st.push(root);
        for(;i<S.size();) {
            int r = findDep(S, i);
            while(st.size()>r-i) st.pop();
            TreeNode* node = st.top();
            int e = findNum(S, r);
            int num = atoi(S.substr(r, e-r).c_str());
            TreeNode* tmp = new TreeNode(num);
            if(node->left) {
                node->right = tmp;
            } else {
                node->left = tmp;
            }
            st.push(tmp);
            i = e;
        }
        return root;
    }
    
    int findNum(string& S, int i) {
        while(i<S.size() && S[i]>='0' && S[i]<='9') i++;
        return i;
    }
    int findDep(string& S, int i) {
        while(i<S.size() && S[i]=='-') i++;
        return i;
    }
};
```