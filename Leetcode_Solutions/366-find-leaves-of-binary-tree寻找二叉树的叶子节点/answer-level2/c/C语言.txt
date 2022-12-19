    分析一下我和大佬的区别
    1.如何删除节点
    链表和树结构等这种由指针构成的数据结构，将一个节点赋值为空，删除一个节点，需要找它的父节点，让父节点指向空。直接root=NULL没有用。
    if (pre != NULL && pre->left == root) pre->left = NULL;
    if (pre != NULL && pre->right == root) pre->right = NULL;
    // root=NULL;//wrong
    2. 返回结果的位置应该在哪里？
    将结果返回给ret的赋值操作的位置。开始放在dfs里面，出错如下：
    输入：
    [1,2,3,4,5]
    输出：
    [[4,5],[3]]
    预期：
    [[4,5,3],[2],[1]]
    [4,5,3]因为不在一颗子树上，被截断。
    dfs(root->left,returnSize,returnColumnSizes,ret,index,path);
    dfs(root->right,returnSize,returnColumnSizes,ret,index,path);
    ret[*returnSize]=malloc(sizeof(int)*(index));    //wrong
    memcpy(ret[*returnSize],path,sizeof(int)*(index));
    (*returnColumnSizes)[*returnSize]=index;
    (*returnSize)++;
    index=0;
    3.一遍查找之后退出了，需要再查找
    while(root->left||root->right){
    }
				
```
void dfs(struct TreeNode* root,int *index,int *path,struct TreeNode* pre ){
    if(root==NULL)return;
    //printf("%d\n",root->val);
    if(root->left==NULL&&root->right==NULL){
        path[*index]=root->val;
        (*index)++;
        if (pre != NULL && pre->left == root) pre->left = NULL;
        if (pre != NULL && pre->right == root) pre->right = NULL;
       // root=NULL;
        return;
    }
    pre=root;
    dfs(root->left,index,path,pre);
    dfs(root->right,index,path,pre);
  
}
int** findLeaves(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ret=malloc(sizeof (int*)*100000);
    int index=0;
    *returnSize=0;
    if(root==NULL)return NULL;
    *returnColumnSizes=malloc(sizeof(int)*100000);
    int *path=malloc(sizeof(int)*100000);
    struct TreeNode* pre;
    while(root->left||root->right){
        dfs(root,&index,path,pre);
        ret[*returnSize]=malloc(sizeof(int)*(index));
        memcpy(ret[*returnSize],path,sizeof(int)*(index));
        (*returnColumnSizes)[*returnSize]=index;
        (*returnSize)++;
        index=0;
    }
    ret[*returnSize]=malloc(sizeof(int));
    ret[*returnSize][0]=root->val;
    (*returnColumnSizes)[*returnSize]=1;
    (*returnSize)++;
    return ret;
}
```