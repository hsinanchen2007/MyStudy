### 解题思路
判断root->left 和root->right是否为NULL，都为NULL 说明到叶子节点了 。开始遍历数组，组成一个整数

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

void dfs(struct TreeNode* root, int count, int* arr, int* ret) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        arr[count++] = root->val;
       
        int ans = 0;
        for (int i = 0; i < count; i++) {
            
            ans = ans * 10 + arr[i];
            printf("%d\n", ans);
        }
        
        *ret += ans;
        //return;
    }
    arr[count++] = root->val;
    
    dfs(root->left, count, arr, ret);
    dfs(root->right, count, arr, ret);
}


int sumNumbers(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int* arr = (int*)malloc(sizeof(int) * 1024);
    int ret = 0;

    memset(arr, 0, sizeof(int) * 1024);

    int count = 0;

    dfs(root, count, arr, &ret);

    return ret;
}
```