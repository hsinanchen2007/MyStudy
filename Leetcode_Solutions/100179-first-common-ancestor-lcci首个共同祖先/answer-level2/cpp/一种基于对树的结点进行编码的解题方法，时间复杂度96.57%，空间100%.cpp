### 解题思路
采用对结点编码的方式，及如果从根节点开始，设定走左子树+'0',走右子树+'1',那么每个结点都可以由一个独一无二的字符串string表示，且string中仅包含0和1；
基于这种思想，获取两个结点的编码string，然后比较两个string前面相似的部分，就可以找到具体在哪个结点是最小公共结点！

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
public:         //采用一种基于编码的思想
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        try{
            if(!root) throw runtime_error("there have mistake input!");
        }catch(runtime_error e){
            return root;
        }
        string p_code,q_code; bool is_get = false;
        pre_order(root,p,p_code,is_get); is_get = false;
        pre_order(root,q,q_code,is_get); TreeNode* node = root;
        for(int i=0; i<p_code.size() && i<q_code.size(); ++i){
            if(p_code[i]!=q_code[i]) break;
            if(p_code[i]=='0') node = node->left;
            else node = node->right;
            //node = node->((p_code[i]==0)?left:right);
        }
        return node;
    }
private:
    void pre_order(TreeNode* root, TreeNode* p, string& str_p, bool& is_get){
        if(root == p){
            is_get = true;
            return;
        }
        if(root->left){
            str_p.push_back('0');  //走左子树为0;
            pre_order(root->left, p, str_p, is_get);
            if(is_get) return;
            str_p.pop_back();
        }
        if(root->right){
            str_p.push_back('1');  //走左子树为0;
            pre_order(root->right, p, str_p, is_get);
            if(is_get) return;
            str_p.pop_back();
        }
        return;
    }
};
```