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

typedef struct Node node;

void Recurse(node* root, int* curDep, int* maxDep)
{
    if (!root) {
        return;
    }
    ++(*curDep);
    if (*curDep > *maxDep) {
        *maxDep = *curDep;
    }
    for (int i = 0; i < root->numChildren; i++) {
        Recurse(root->children[i], curDep, maxDep);
    }
    --(*curDep);
    return;
}

int maxDepth(struct Node* root) {
    int curDep = 0;
    int maxDep = 0;
    Recurse(root, &curDep, &maxDep);
    return maxDep;
}
```