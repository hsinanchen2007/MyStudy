### 解题思路
直接按照层次遍历，多一层次深度加1

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
 #define INT_MAX 10000
int maxDepth(struct TreeNode* root){
    if(root ==NULL){
        return 0;
    }
    struct TreeNode *queue[INT_MAX];
    int *arr = (int *)malloc(sizeof(int)*INT_MAX);
    int front = 0;
    int end = 0;
    //printf("%d",end);
    queue[end++%INT_MAX]=root;
    int size=0;
    //printf("%d",end);
    while(end>front){
        int step = end-front;
        for (int j = 0; j < step; j++) {
            struct TreeNode *cur =  queue[front++];
           // arr[j] =cur->val;
            if(cur->left)
            queue[end++]= cur->left;
            if(cur->right)
            queue[end++]= cur->right;
        }
        size++;
    }
    
    return size;
}
```