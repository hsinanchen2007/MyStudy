### 解题思路
此处撰写解题思路

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
int read(struct TreeNode* root1)
{
    // printf("%d",root1->val);
    return root1->val;
}

int  midsort (struct TreeNode* root1, int * num, int* i  ) 
{
    if (root1->left != NULL)  midsort(root1->left, num , i);
    num[*i] = read(root1);
    (*i) += 1;
    // printf("%d",*i);
    if (root1->right != NULL)  midsort(root1->right,num ,i);
    return *i ;
}

int  sort(int num1[] , int num2[],int num[],int length1,int length2 )
{
    int i = 0 ;
    int j = 0 ;
    int k = 0 ;
    while(i <length1 && j < length2)
    {
        if(num2[j] < num1[i])
            num[k++] = num2[j++];
        else num[k++] = num1[i++];
    }

    if(i <length1)
    {
        while(i <length1)
        {
            num[k++] = num2[j++];
        }
    }

    if(j < length2)
    {
        while(j < length2)
        {
            num[k++] = num1[i++];
        }
    }
    return length1+length2;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int i =0;
    int j= 0;
    int * k ;
    int num1[5000] ;
    int num2[5000]  ;
    int length1 =0;
    int length2 =0;
    if (root1 != NULL)
    {   
        k = &i;
        length1 = midsort(root1 , num1 , k );   
    }
    if(root2 != NULL)
    {
        k = &j;
        length2 = midsort(root2 , num2 , k);
    }
    
    // printf("%d",num2[length2-1]);printf("%d",num2[length2-2]);printf("%d",num2[length2-3]);
    int *num ;
    num = calloc(10000,sizeof(int));
    i = 0 ;
    j = 0 ;
    int n = 0 ;
   
    while(i <length1 && j < length2)
    {
        if(num2[j] < num1[i])
            num[n++] = num2[j++];
        else num[n++] = num1[i++];
        // printf("%d--",num[n-1]);
    }
    if(i <length1)
    {
        while(i <length1)
        {
            // printf("%d++",num1[i]);
            num[n++] = num1[i++];
        }
    }
    if(j < length2)
    {
        while(j < length2)
        {
            
            num[n++] = num2[j++];
            // printf("%d^^",num[n-1]);

        }
    }
    // for(int m =0;m<length1+length2;m++)
    //     printf("%d",num[m]);
    // num[length1+length2] = NULL;
     *returnSize = length1+length2;
    return num;
}
```