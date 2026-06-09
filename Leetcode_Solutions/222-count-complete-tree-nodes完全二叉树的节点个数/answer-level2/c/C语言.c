我有点不服，这个东西的时长判断真的有问题。。。一样的代码和运行时间不一样。内存100%
```
void Search(struct TreeNode* node,int* p){
    if (node ){
        (*p)++;
        Search(node->left,p);
        Search(node->right,p);
    }
    return;
}

int countNodes(struct TreeNode* root){
    int count = 0;
    Search(root,&count);
    return count;
}
```
