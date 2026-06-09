```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    struct TreeNode** save=NULL;
    int ** ret=NULL;
    *returnColumnSizes=NULL;
    if(root)
    {
        *returnSize=1;
        *returnColumnSizes=(int *)malloc(sizeof(int));
        (*returnColumnSizes)[0]=1;
        ret=(int**)realloc(ret,sizeof(int *));
        ret[0]=(int *)malloc(sizeof(int));
        ret[0][0]=root->val;
        save=(struct TreeNode**)realloc(save,sizeof(struct TreeNode*));
        save[0]=root;
        while(1)
        {
            struct TreeNode** tmp=NULL;
            int size=0;
            int *num=NULL;
            for(int i=0;i<(*returnColumnSizes)[(*returnSize)-1];i++)
            {
                if(save[i]->left)
                {
                    size++;
                    tmp=(struct TreeNode**)realloc(tmp,sizeof(struct TreeNode*)*size);
                    num=(int*)realloc(num,sizeof(int)*size);
                    tmp[size-1]=save[i]->left;
                    num[size-1]=save[i]->left->val;
                }
                if(save[i]->right)
                {
                    size++;
                    tmp=(struct TreeNode**)realloc(tmp,sizeof(struct TreeNode*)*size);
                    num=(int*)realloc(num,sizeof(int)*size);
                    tmp[size-1]=save[i]->right;
                    num[size-1]=save[i]->right->val;
                }
            }
            if(size==0)break;
            else
            {
                (* returnSize)++;
                *returnColumnSizes=(int *)realloc(*returnColumnSizes,sizeof(int)*(* returnSize));
                (*returnColumnSizes)[(* returnSize)-1]=size;
                ret=(int**)realloc(ret,sizeof(int *)*(* returnSize));
                ret[(* returnSize)-1]=num;
                free(save);
                save=tmp;
            }
        }
    }
    free(save);
    return ret;
}
```