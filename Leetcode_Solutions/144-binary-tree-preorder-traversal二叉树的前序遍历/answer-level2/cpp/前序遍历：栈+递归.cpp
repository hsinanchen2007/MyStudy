### 解题思路
此处撰写解题思路

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
    /*vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }*/
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p=root;
        vector<int> res;
        while(p||!s.empty()){
            while(p){
                res.push_back(p->val);//访问该点
                s.push(p);//记录到栈
                p=p->left;//左子树
            }
        p=s.top();s.pop();//按先序，父节点访问-左子树，还差柚子树
        //所以通过栈顶拿到父节点，进入柚子树后，此节点就报废了pop掉
        p=p->right;
        }
        return res;
    }

};


```