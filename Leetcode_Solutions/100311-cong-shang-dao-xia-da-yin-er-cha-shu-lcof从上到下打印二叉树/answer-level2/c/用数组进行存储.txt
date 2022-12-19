
```

int* levelOrder(struct TreeNode* root, int* returnSize){
    if (NULL == root)
    {
        *returnSize = 0;
        return NULL;
    }
    int *res = (int*)malloc(sizeof(int)*2020);
    int resId = 0;
    res[resId++] = root->val;
    struct TreeNode *temp[2020];
    temp[0] = root;
    struct TreeNode* newRoot;
    int newTemp = 1;
    int startTemp = 0;
    while(newTemp != 0)
    {
        newTemp = resId;
        for(int i = startTemp; i< resId; i++)
        {
            newRoot = temp[i];
            if(NULL != newRoot->left) 
            {
                temp[resId] = newRoot->left;
                res[resId++] = newRoot->left->val;
            }
            if(NULL != newRoot->right) 
            {
                temp[resId] = newRoot->right;
                res[resId++] = newRoot->right->val;
            }
        }
        startTemp = resId - 1;
        newTemp = resId - newTemp;
    }
    *returnSize = resId;
    return res;
}
```



话说题目不是说最大1000个节点，测试用例怎么两千多个。。。