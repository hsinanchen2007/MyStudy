### 解题思路
每次判断本节点是否删除，直到不删除的节点为止，则为头结点。
迭代中保存父节点，若是头结点则要修改对应子节点指针。
随便写的，参数太多，后面还可以优化。看有没有时间吧。

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

void dfs(struct TreeNode *root, struct TreeNode *parent, int type, int headFlag, int *to_delete, int to_deleteSize, struct TreeNode** array, int *num){
    bool isHead = true;
    int nextHeadFlag = 0;
    if(root == NULL){
        return;
    }
    for(int i = 0; i < to_deleteSize; i++){
        if(root->val == to_delete[i]){
            if(parent != NULL){
                if(type == 1){
                    (*parent).left = NULL;
                }else{
                    (*parent).right = NULL;
                }
            }
            isHead = false;
            nextHeadFlag = 1;
            break;
        }
    }
    if((headFlag == 1) && (isHead == true)){
        array[*num] = root;
        *num = *num + 1;
        nextHeadFlag = 0;
    }

    dfs(root->left, root, 1, nextHeadFlag, to_delete, to_deleteSize, array, num);
    dfs(root->right, root, 2, nextHeadFlag, to_delete, to_deleteSize, array, num);
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    int num = 0;
    struct TreeNode ** retArray = (struct TreeNode **)malloc(sizeof(struct TreeNode*) * (to_deleteSize * 2 + 1));
    dfs(root, NULL, 0, 1, to_delete, to_deleteSize, retArray, &num);
    *returnSize = num;
    return retArray;
}
```