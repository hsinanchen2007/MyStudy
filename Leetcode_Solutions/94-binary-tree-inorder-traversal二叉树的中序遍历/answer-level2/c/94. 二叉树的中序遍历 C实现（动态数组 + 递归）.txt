### 解题思路
    无法确定树的节点个数，c实现主要难点在内存申请上，自己写了个简易的arraylist。

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ARRINITSIZE 10

typedef struct TreeNode node;

typedef struct {
    int* arr;
    int index;
    int size;
} arrayList;

void Recurse(node* root, arrayList* l)
{
    if (!root) {
        return;
    }
    Recurse(root->left, l);
    l->arr[l->index++] = root->val;
    if (l->index == l->size) {
        l->size <<= 1;
        int mallocSize = sizeof(int) * l->size;
        int* newArr = (int*)malloc(mallocSize);
        memcpy(newArr, l->arr, mallocSize >> 1);
        free(l->arr);
        l->arr = newArr;
    }
    Recurse(root->right, l);
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    arrayList* l = (arrayList*)malloc(sizeof(arrayList));
    l->index = 0;
    l->size = ARRINITSIZE;
    l->arr = (int*)malloc(sizeof(int) * l->size);
    Recurse(root, l);
    *returnSize = l->index;
    return l->arr;
}
```