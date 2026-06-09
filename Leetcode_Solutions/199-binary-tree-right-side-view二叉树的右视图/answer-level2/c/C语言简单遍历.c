主要实现思路：
1、每次遍历一层，遍历的时候从右向左，并且记录下所有数据
2、接着遍历下一层，一直到遍历到最后
3、将每层的第一个元素记录下来

这个思路比较简单，为了解决简单，我使用了最大数据，这个方法不是最优解，仅供参考

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define  MAX_RETURN_SIZE   2048

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
    int index ;
    int count = 0;
    int curNum = 0;
    int nextNum = 0;
    int *retValue = NULL;
    struct TreeNode **curNode = NULL;
    struct TreeNode **nextNode = NULL;
    struct TreeNode **tempNode = NULL;

    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    

    retValue = (int *)malloc(MAX_RETURN_SIZE * sizeof(int));
    if (retValue == NULL)
    {
        return NULL;
    }
    
    curNode = (struct TreeNode **)malloc(MAX_RETURN_SIZE * sizeof(struct TreeNode *));
    nextNode = (struct TreeNode **)malloc(MAX_RETURN_SIZE * sizeof(struct TreeNode *));
    if (curNode == NULL || nextNode == NULL)
    {
        free(curNode);
        free(nextNode);
        return NULL;
    }
    memset(curNode, 0x0, MAX_RETURN_SIZE * sizeof(struct TreeNode *));
    memset(nextNode, 0x0, MAX_RETURN_SIZE * sizeof(struct TreeNode *));

    curNode[curNum++] = root;
    for (; ;)
    {
        if (curNum == 0)
        {
            break;
        }

        //printf("\r\n curNum = %d", curNum);
        
        /* get firts ele */
        if (curNode[0] != NULL)
        {
            //printf("\r\n count = %d val= %d", count, curNode[0]->val);
            retValue[count++] = curNode[0]->val;
        }
        
        for (index = 0; index < curNum; index++)
        {
            /* code */
            if (curNode[index]->right != NULL)
            {
                nextNode[nextNum++] = curNode[index]->right;
            }

            /* code */
            if (curNode[index]->left != NULL)
            {
                nextNode[nextNum++] = curNode[index]->left;
            }
        }

        //printf("\r\n curNum end = %d, nextNum=%d", curNum, nextNum);
        curNum = nextNum;
        tempNode = curNode;
        curNode = nextNode;
        nextNode = tempNode;
        nextNum = 0;
    }
    
    *returnSize = count;
    free(curNode);
    free(nextNode);
    return retValue;
}
```
