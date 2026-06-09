### 解题思路
说白了就是先序遍历上再加些别的
### 代码

```cpp
class Solution {
public:
    stringstream out;
    void search(TreeNode* s){
        if(s==NULL){
            return;
        }
        out<<"(";
        out<<s->val;
        if(s->left==NULL && s->right!=NULL){
            out<<"()";
        }
        search(s->left);
        search(s->right);
        out<<")";
        return;
    }
    string tree2str(TreeNode* t) {
        int c=0; 
        if(t==NULL){
            return out.str();
        }
        out<<t->val;
        if(t->left==NULL && t->right!=NULL){
            out<<"()";
        }
        search(t->left);
        search(t->right);
        return out.str();
    }
};
```