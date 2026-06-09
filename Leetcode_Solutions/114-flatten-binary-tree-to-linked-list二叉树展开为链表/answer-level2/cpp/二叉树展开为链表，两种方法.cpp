题目解析：
按题目中的意思是，把树按先序遍历的顺序转换成链表形式，结点的右指针指向下一个结点，左指针指向空；
法一：
需要更改结点左右指针的顺序，从根节点开始，结点的左孩子放到结点的右指针，结点的右孩子放到左孩子最后指针后面；依次向下，直至整棵树变为链表。
```
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* p = root;
        while(p){
            TreeNode* p_r = p->right;//记录右子树的值
            p->right = p->left;     //左子树挂到右子树上
            p->left = nullptr;     //*
            TreeNode* t = p;//寻找原左子树的最右结点
            while(t->right)
                t = t->right;
            t->right = p_r;//原右子树挂到最后节点后
            p = p->right;
        }
    }
};
```
法二：
改造后序遍历；
遍历顺序改为，右左中，顺序与先序遍历刚好相反，且遍历某节点时，其左右子树均已经遍历过，可以随意修改其左右指针，不会影响遍历顺序。
只需修改后序遍历两处即可：
1、左右子树的遍历顺序调换。
2、添加一个指针pre指向上一个访问的结点，访问结点改为将结点右指针指向pre,左指针指向空
递归形式：
```
class Solution {
private:
    TreeNode* pre = nullptr;
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};
```
迭代形式：
```
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->right;
            }
            if(!s.empty()){
                p = s.top();
                if(p->left && pre != p->left)
                    p = p->left;
                else{
                    p->right = pre;
                    p->left = nullptr;
                    pre = p;
                    p = nullptr;
                    s.pop();
                }
            }
        }
    }
};
```

