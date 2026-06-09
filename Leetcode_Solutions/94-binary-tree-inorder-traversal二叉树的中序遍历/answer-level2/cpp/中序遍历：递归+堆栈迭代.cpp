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
/*    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();//尾部结束条件
        inorderTraversal(root->left);//进入左边
        res.push_back(root->val);//访问根节点
        inorderTraversal(root->right);//进入右边
        return res;//返回结果
    }*/
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p=root;
        vector<int> res;
        while(p||!s.empty()){//p用来遍历树，s用来push遍历但暂时不访问的节点
            while(p){
                s.push(p);
                p=p->left;
            }//遍历左子树
            p=s.top();s.pop();//栈顶为最后最后一个节点，用了就pop
            res.push_back(p->val);
            p=p->right;//转柚子树
        }
        return res;
    }

};
```