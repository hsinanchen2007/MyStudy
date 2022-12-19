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

#include<stdio.h>
#include<stdlab.h>
#define MaxSize 1000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if(!root)
    {
        *returnSize=0;
        return NULL;
    }
    struct TreeNode* quene[MaxSize];//建立循环队列
    int front=0,rear=0,i=0,k=0,sum=0;//k为树的层数，sum为一层中结点的个数，i用来遍历同一层结点
    * returnColumnSizes=(int*)malloc(MaxSize*sizeof(int));
    /*
    returnColumnSizes本身为数组（int*类型，用来申请动态数组），因为出现在return中，又想要他的值，所以函数传进来的就是数组的指针，也就是int**类型了。
    第一遍没太看明白，这里笔记一下~    
    */
    int** result=(int**)malloc(MaxSize*sizeof(int*));//返回一个二维数组
    rear=(rear+1)%MaxSize;//循环队列的插入，后面同理
    quene[rear]=root;//根节点入队列
    while(rear!=front)
    {
        sum=(rear-front+MaxSize)%MaxSize;//计算本层节点个数
        (*returnColumnSizes)[k]=sum;
        /*将各层结点数存储到returnColumnSizes数组中，returnColumnSizes[0]中储存的就是根节点=1个；returnColumnSizes[1]中就是第一层的节点个数，题例就是2，等等。。。          */
        result[k]=(int*)malloc(sum*sizeof(int));//在二维数组中添加一维数组，大小=该层结点个数
        

        for(i=0;i<sum;i++)//遍历该层结点，取出数值存进result中。
        {
            front=(front+1)%MaxSize;
            result[k][i]=quene[front]->val;
            if(quene[front]->left)//左右结点依次进入队列
            {
                rear=(rear+1)%MaxSize;
                quene[rear]=quene[front]->left;
            }
            if(quene[front]->right)
            {
                rear=(rear+1)%MaxSize;
                quene[rear]=quene[front]->right;
            }
        }
        k++;
    }

    *returnSize=k;

    return result;



}
```
