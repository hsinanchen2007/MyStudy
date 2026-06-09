### 解题思路
先吐槽下，C语言解题真累！！！
思路上是这样，如果我们需要 f(n)的结果，
那么有两种可能： 1： f(n-1) 所有结果前面加一个根节点 n, 并将f(n-1)的树作为左子树。
                2：f(n-1)里每一种树从根节点开始，遍历右子树，每个右子树节点上添加一个节点 n, 
                  然后把原右子树作为新节点n的左子树。

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
 void printNode(const struct TreeNode *node) {
     
     if(node->left != NULL) {
        printf("left:");
        printNode(node->left);
     }
     printf("middle:%d ", node->val);
     if(node->right != NULL) {
        printf("right:");
        printNode(node->right);
     }
}

struct TreeNode* buildNode(int value) {
    struct TreeNode *res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(res, 0, sizeof(struct TreeNode));
    res->val = value;
    return res;
}


struct TreeNode* cloneAllNode(const struct TreeNode *source) {
    struct TreeNode *res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(res, 0, sizeof(struct TreeNode));
    res->val = source->val;
    if (source->left != NULL) {
        res->left = cloneAllNode(source->left);
    }
    if (source->right != NULL) {
        res->right = cloneAllNode(source->right);
    }
    
    return res;
}


struct TreeNode* searchRightValue(struct TreeNode* sourceNode, int value) {    
    if (sourceNode == NULL) {
        return NULL;
    }
    struct TreeNode *tmpNode = sourceNode;
    while (tmpNode != NULL) {        
        if (tmpNode->val == value) {
            return tmpNode;
        }
        tmpNode = tmpNode->right;
    }
    return NULL;
}


struct TreeNode** addNewNode(struct TreeNode* sourceNode, int value, int *size)
{
    *size = 0;
    struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    memset(res, 0, sizeof(struct TreeNode*));    
    if (sourceNode == NULL) {        
        struct TreeNode* tmpNode = buildNode(value);
        (*size)++;        
        res[0] = tmpNode;
        return res;
    }

    struct TreeNode* subNode = sourceNode;
    // add to right node
    while(subNode != NULL) {                
        // printf("add sub node value:%d, %d\n", subNode->val, (*size));
        struct TreeNode *tmpResNode = cloneAllNode(sourceNode);
        struct TreeNode *subTmpNode = searchRightValue(tmpResNode, subNode->val);
        if (subTmpNode != NULL) {
            (*size)++;
            res = (struct TreeNode**)realloc(res, sizeof(struct TreeNode*)*(*size));
            struct TreeNode* subAddNode = buildNode(value);
            subAddNode->left = subTmpNode->right;
            subTmpNode->right = subAddNode;                        
            res[(*size) - 1] = tmpResNode;
            // printf("add node:%d,%d\n", (*size), tmpResNode->val);
        }        
        subNode = subNode->right;
    }

    (*size)++;
    res = (struct TreeNode**)realloc(res, sizeof(struct TreeNode*)*(*size));    
    struct TreeNode* subAddNode = buildNode(value);
    subAddNode->left = sourceNode;    
    res[(*size) - 1] = subAddNode;

    return res;
}

void addNewNodeValue(struct TreeNode*** nodeRes, int *size, int nodeValue)
{    
    // printf("============add value to node list:%d,%d\n", (*size), nodeValue);
    struct TreeNode** newRes = malloc(sizeof(struct TreeNode*));
    // nodeValue must be the max value.
    int newSize = 0;
    for (int i = 0; i < (*size); i++) {                
        int flagIndex = newSize;
        int tmpNodeSize = 0;
        struct TreeNode** tmpResNode = addNewNode((*nodeRes)[i], nodeValue, &tmpNodeSize);
        // printf("add node finish:%d,%d,%d\n", i, tmpNodeSize, flagIndex);
        newSize += tmpNodeSize;
        newRes = (struct TreeNode**)realloc(newRes, sizeof(struct TreeNode*)*(newSize));        
        memcpy(newRes+flagIndex, tmpResNode, sizeof(struct TreeNode*) * tmpNodeSize);        
    }

    (*nodeRes) = newRes;
    *size = newSize;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize){
    struct TreeNode** res;
    *returnSize = 0;
    if (n <= 0) {
        return NULL;
    }
    
    if (n == 1) {
        *returnSize = 1;
        struct TreeNode* node = buildNode(1);
        res = malloc(sizeof(struct TreeNode*));
        res[0] = node;
        return res;
    }
    res = generateTrees(n - 1, returnSize);
    addNewNodeValue(&res, returnSize, n);    
    return res;
}
```