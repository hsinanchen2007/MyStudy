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
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAXSIZE 1000
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int **ret=(int**)malloc(sizeof(int*)*MAXSIZE);
    int returnColumnSizes[MAXSIZE];
    int i,j,front=0,rear=0;
    struct TreeNode *p,*queue[MAXSIZE];
    *returnSize=0;
    queue[root?rear++:rear]=root;
    while(front<rear){
       
        returnColumnSizes[*returnSize]=rear-front;
        ret[*returnSize]=(int*)malloc(sizeof(int)*returnColumnSizes[*returnSize]);
        for(i=0;i<returnColumnSizes[*returnSize];i++){
             p=queue[front++%MAXSIZE];
             ret[*returnSize][i]=p->val;
             if(p->left)queue[rear++%MAXSIZE]=p->left;
             if(p->right)queue[rear++%MAXSIZE]=p->right;
        }
        (*returnSize)++;
    }
    double *result=(double*)malloc(sizeof(double)*(*returnSize));
    double sum=0;
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<returnColumnSizes[i];j++){
            sum+=ret[i][j];
        }
        result[i]=sum/returnColumnSizes[i];
        sum=0;
    }
    
    return result;
}
```
