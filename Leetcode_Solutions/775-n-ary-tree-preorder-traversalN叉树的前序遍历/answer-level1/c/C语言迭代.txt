### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) 
{
    *returnSize = 0;
    if (!root)
        return 0;
    int *res = (int*)malloc(sizeof(int) * 10240);
    struct Node **queue = (struct Node**)malloc(sizeof(struct Node*) * 10240);
    int i, p = 0;
    queue[p++] = root;
    struct Node *temp;
    while (p)
    {
        temp = queue[--p];
        res[(*returnSize)++] = temp->val;
        for (i = temp->numChildren - 1; i >= 0; i--)
            queue[p++] = temp->children[i];
    }
    return res;
}
```