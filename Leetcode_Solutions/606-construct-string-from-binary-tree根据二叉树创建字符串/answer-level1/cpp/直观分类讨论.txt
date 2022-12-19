### 解题思路
 根节点不需要括号 
 除根节点外，每个节点开始时需要左括号，结束需要右括号
 左子树不为空，右子树为空，右子树不需要括号
 左子树为空，右字数不为空，左子树需要空括号
 如果是叶子节点，返回

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
    string ans;
    void pre_tranverse(TreeNode *node) {
        if (node == nullptr) return;
        
        ans += "(" + to_string(node->val);
        if (!node->left && !node->right){
            ans += ")";
            return;
        }else if (node->left==nullptr && node->right!=nullptr) {
            ans += "()";
        }
        pre_tranverse(node->left);
        
        pre_tranverse(node->right);
        ans += ")";
        
    }
    string tree2str(TreeNode* t) {

        pre_tranverse(t);
        // 去除首位括号
        string ret;
        if (ans!=""){
            for (int  i = 1; i< ans.size()-1; i++){
                ret += ans[i];
            }
        }else{
            ret = ans;
        }
        return  ret;
    }
};
```