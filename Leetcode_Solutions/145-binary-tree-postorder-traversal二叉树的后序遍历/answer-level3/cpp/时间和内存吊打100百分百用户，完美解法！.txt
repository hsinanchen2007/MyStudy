```
class Solution {
public:
    vector<int> ret;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        TreeNode* r;
        while (!stk.empty() || p) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            r = p->right;
            if (!r) {                      //该节点无右孩子，可以输出了，否则继续遍历右子树
                while (p->right == r) {    //这里很关键
                    ret.push_back(p->val); //
                    stk.pop();
                    r = p;                 //r用于右孩子判断
                    if(stk.empty()) {
                        p->right = NULL;   //访问到了根节点，退出所有循环
                        break;
                    } else {
                        p = stk.top();
                    }
                }
            }
            p = p->right;
        }
        return ret;
    }
};
```
