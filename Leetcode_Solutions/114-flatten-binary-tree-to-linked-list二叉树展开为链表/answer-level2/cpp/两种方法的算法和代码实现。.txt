方法1：
投机取巧得方法，但并不满足in-placez就地转换的条件。这个方法比较简单：首先前序遍历取出各节点的地址放入vector中，然后再顺次连接转换为单链表。
代码如下：
```
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        vector<TreeNode*> node;
        preorder(root,node);
        for(int i=0;i<node.size()-1;i++){
            node[i]->left=NULL;
            node[i]->right=node[i+1];
        }
        return;
    }
private:
    void preorder(TreeNode* root,vector<TreeNode*> &node){
        if(!root){
            return;
        }
        node.push_back(root);
        preorder(root->left,node);
        preorder(root->right,node);
    }
};
```
运行结果：执行用时 :16 ms, 27.46%；10 MB, 72.04%。


方法2：
基本思路：前序遍历每个节点，先调用左结点，左结点返回后，如果该节点有右子树，就把右子树接到左子树的末尾，这时该根节点的整个子树就成为了单链；因为要右子树移接到左子树的末尾，所以要先有个指针last始终指向左子树的叶节点（即最末节点），移接结束后，根节点的u右子树要z置空，last更新到新左子树末尾。递归调用结束后，返回的是单链但未必每个节点都是左孩子为空（题目要求），所以还需要左转右，左置空。

```
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        TreeNode* last=root;
        //找最右边的叶节点
        while(last->left||last->right){
            if(last->left){
                last=last->left;
            }
            else if(last->right){
                last=last->right;
            }  
        }
        //cout<<last->val<<endl;
        aftorder(root, last);
        last=root;
        while(last){
            if(last->left){
                last->right=last->left;
                last->left=NULL;
            }
            last=last->right;
        }
       return; 
    }
private:
    void aftorder(TreeNode* root,TreeNode*&last){
        if(!root){
            return;
        }
        //访问左子树
        aftorder(root->left, last);
        //访问右子树前先进行移花接木，将右子树接到last上
        if(root->right&&root->left){
            last->right=root->right;
            root->right=NULL;
            aftorder(last->right, last);
        }
        else{
            //访问右子树
            aftorder(root->right, last);  
        } 
        //更新last
        while(last->left||last->right){
            if(last->left){
                last=last->left;
            }
            else if(last->right){
                last=last->right;
            }  
        }
        cout<<last->val<<endl;
    }
};
```
运行结果：12ms,62.75%;9.8MB,77.22%.
