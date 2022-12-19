### 解题思路
先得到树的深度，然后从顶层开始遍历二叉树的每一层，为了减少空间占用，需要记录上一层的非空节点，然后依次为依据，在上一层非空节点的子节点中寻找非空的节点（即当前层的非空节点），记录然后更新。最后循环遍历。
执行耗时：4ms；内存占用：7M。

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    if(root==NULL){
        *returnSize=0;
        returnColumnSizes=NULL;
        return NULL;
    }

    int ColumMax=maxDepth(root);
    *returnSize=ColumMax;
    int **arr=malloc(sizeof(int*)*ColumMax);
    *returnColumnSizes=(int*)calloc(ColumMax,sizeof(int));
    //填入初始数据
    arr[ColumMax-1]=malloc(sizeof(int)*1);
    arr[ColumMax-1][0]=root->val;
    (*returnColumnSizes)[ColumMax-1]=1;

    struct TreeNode** cur;  //存放当前层所有非空节点
    struct TreeNode** next; //存放下一层的所有非空节点
    cur=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*1);  //初始化当前层为第一层
    cur[0]=root;
    int i,j;
    for(i=1;i<ColumMax;i++){
        int frontNum=(*returnColumnSizes)[ColumMax-i];  //记录第i-1层的非空节点数目
        struct TreeNode** tmp_p;    //存放当前层的非空节点
        //当前层非空节点数最大为2*frontNum
        tmp_p=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2*frontNum);
        int k=0,m=0;
        int *tmp=(int*)malloc(sizeof(int)*2*frontNum);  //存放当前层的节点数据
        //存放下一层的非空节点
        next=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2*frontNum);
        //筛选当前层的每一个非空节点产生的非空子节点，将其存到tmp_p
        for(j=0;j<frontNum;j++){
            next[2*j]=cur[j]->left;
            next[2*j+1]=cur[j]->right;

            for(int n=0;n<2;n++){
                if(next[2*j+n]){
                tmp[k++]=next[2*j+n]->val;
                tmp_p[m]=(struct TreeNode*)malloc(sizeof(struct TreeNode*)*1);
                tmp_p[m++]=next[2*j+n];
                }
            }
        }
        free(cur);    //释放前一个tmp_p       
        cur=tmp_p;  //更新当前节点
        arr[ColumMax-1-i]=(int*)malloc(sizeof(int)*k);
        memcpy(arr[ColumMax-1-i],tmp,sizeof(int)*k);
        free(tmp);
        (*returnColumnSizes)[ColumMax-1-i]=k;
    }
    return arr;
}

int maxDepth(struct TreeNode* root){

    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    int right=maxDepth(root->right)+1;
    int left=maxDepth(root->left)+1;
    return (right>left?right:left);
}
```