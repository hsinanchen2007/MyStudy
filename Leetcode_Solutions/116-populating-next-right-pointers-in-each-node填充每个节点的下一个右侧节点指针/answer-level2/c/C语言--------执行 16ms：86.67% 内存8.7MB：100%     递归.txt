### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
void DFS(struct Node*root){
        if(root==NULL)   return;
        if(root->left&&root->right){
        struct Node*p,*q;
        p=root->left;
        q=root->right;
        p->next=q;
        while(p->right&&q->left){
            p=p->right;
            q=q->left;
            p->next=q;
        }
    }
    DFS(root->left);
    DFS(root->right);
}
void DFS1(struct Node*root){
    if(root!=NULL){
    root->next=NULL;
    DFS1(root->right);
    }  
}
struct Node* connect(struct Node* root) {
if(root==NULL)  return NULL;
DFS(root);
DFS1(root);
return root;
}
```