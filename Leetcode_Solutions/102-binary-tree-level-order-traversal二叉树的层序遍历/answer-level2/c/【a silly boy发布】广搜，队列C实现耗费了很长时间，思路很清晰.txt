```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;
typedef struct ListData {
    TreeNode treeNode;
    struct ListData *next;
}ListData;

ListData *g_listData;
ListData *g_listDataTmp;

void ListNodePush(TreeNode *treeNode, bool isTmp) {
    ListData *startListNode;
    if (isTmp == false) {
        startListNode = g_listData;
    } else {
        startListNode = g_listDataTmp;
    }
    g_listData;
    ListData *tmpListData = (ListData *)malloc(sizeof(ListData));
    tmpListData->treeNode.val = treeNode->val;
    tmpListData->treeNode.left = treeNode->left;
    tmpListData->treeNode.right = treeNode->right;
    tmpListData->next = NULL;
    //printf("PUSH: tmpListData->treeNode.val: %u\n", tmpListData->treeNode.val);
    if (isTmp == false) {
        if (g_listData == NULL) {
            g_listData = tmpListData;
        } else {
            while (g_listData->next != NULL) {
                g_listData = g_listData->next;
            }
            g_listData->next = tmpListData;
            g_listData = startListNode;
        }
    } else {
        if (g_listDataTmp == NULL) {
            g_listDataTmp = tmpListData;
        } else {
            while (g_listDataTmp->next != NULL) {
                g_listDataTmp = g_listDataTmp->next;
            }
            g_listDataTmp->next = tmpListData;
            g_listDataTmp = startListNode;
        } 
    }
}

bool ListNodePop(TreeNode *treeNode, bool isTmp) {
    ListData *tmpListNode;
    if (isTmp == false) {
        tmpListNode = g_listData;
        if (g_listData == NULL) {
            return false;
        }
        treeNode->val = g_listData->treeNode.val;
        treeNode->left = g_listData->treeNode.left;
        treeNode->right = g_listData->treeNode.right;

        g_listData = g_listData->next;
        tmpListNode->next = NULL;
        free(tmpListNode);
        //printf("POP: treeNode->val: %u\n", treeNode->val);
    } else {
        tmpListNode = g_listDataTmp;
        if (g_listDataTmp == NULL) {
            return false;
        }
        treeNode->val = g_listDataTmp->treeNode.val;
        treeNode->left = g_listDataTmp->treeNode.left;
        treeNode->right = g_listDataTmp->treeNode.right;

        g_listDataTmp = g_listDataTmp->next;
        tmpListNode->next = NULL;
        free(tmpListNode);
        //printf("POPTMP: treeNode->val: %u\n", treeNode->val);
    }

    return true;
}

void SubFuncDepth(TreeNode* root, int tmpDepth, int *detph) {
    if (root == NULL) {
        if (*detph < tmpDepth) {
            *detph = tmpDepth;
        }
        return;
    }
    tmpDepth++;
    SubFuncDepth(root->left, tmpDepth, detph);
    SubFuncDepth(root->right, tmpDepth, detph);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int listNodeSize = 0;
    int i;
    int listNodeSizeTmp = 0;
    int level = 0;
    int **returnValue;
    int depth = 0;
    int tmpDepth = 0;

    if (root == NULL) {
        *returnSize = 0;
        (*returnColumnSizes) =  (int *)malloc(sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }

    SubFuncDepth(root, tmpDepth, &depth);
    //printf("depth: %u\n", depth);
    returnValue = (int **)malloc(depth * sizeof(int *));
    (*returnColumnSizes) = (int *)malloc(depth * sizeof(int));

    g_listData = (ListData *)malloc(sizeof(ListData));
    g_listData->next = NULL;
    g_listData->treeNode.val = root->val;
    g_listData->treeNode.left = root->left;
    g_listData->treeNode.right = root->right;
    listNodeSize = 1;
    
    while(listNodeSize != 0) {
        
        //层输出
        listNodeSizeTmp = 0;
        //printf("---1 listNodeSize: %u\n", listNodeSize);
        for (i = 0; i < listNodeSize; i++) {
            ListNodePop(root, false);
            ListNodePush(root, true);
        }
        listNodeSizeTmp = listNodeSize;
        listNodeSize = 0;
        (*returnColumnSizes)[level] = listNodeSizeTmp;
        returnValue[level] = (int *)malloc(listNodeSizeTmp * sizeof(int));

        //层输入
        level++;
        for (i = 0; i < listNodeSizeTmp; i++) {
            ListNodePop(root, true); 
            //printf("---2: val: %u\n", root->val);
            returnValue[level - 1][i] = root->val;
            if (root->left != NULL) {
                listNodeSize++;
                ListNodePush(root->left, false);
            }
            if (root->right != NULL) {
                listNodeSize++;
                ListNodePush(root->right, false);
            }
        }
    }
    *returnSize = level;
    return returnValue;
}
```
