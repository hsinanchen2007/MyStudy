1.分治递归
```
#include <stdio.h>
#include <stdlib.h>
// /**
//   Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };
struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right)
        return NULL;
    struct TreeNode* t;
    t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (left + right) / 2;
    t->val = nums[mid];
    t->left = helper(nums, left, mid - 1);
    t->right = helper(nums, mid + 1, right);
    return t;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}

```

 2.层次遍历建树+中序遍历赋值
```
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10000
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };
//既然是平衡二叉树，那么它的高度一定是logn
//一颗高度为logn的二叉树，除了最后一层外每一层都是满的，类似完全二叉树
//所以可以先创建一个高度为logn的完全二叉树（用类似层次遍历的方法）
//再对这颗完全二叉树进行中序遍历并赋值
void InOrder(struct TreeNode* root, int* nums, int* i) {
    if (root != NULL) {
        InOrder(root->left, nums, i);
        root->val = nums[(*i)++];
        InOrder(root->right, nums, i);
    }
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0)
        return NULL;
    struct TreeNode *root, *p, *q, *qu[MaxSize];
    int rear = 0, front = 0, count = 1;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = root->right = NULL;
    rear = (rear + 1) % MaxSize;
    qu[rear] = root;
    while (count < numsSize) {
        front = (front + 1) % MaxSize;
        p = qu[front];
        q = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        p->left = q;
        q->left = q->right = NULL;
        rear = (rear + 1) % MaxSize;
        qu[rear] = q;
        count++;
        if (count < numsSize) {
            q = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            p->right = q;
            q->left = q->right = NULL;
            rear = (rear + 1) % MaxSize;
            qu[rear] = q;
            count++;
        }
    }
    count = 0;
    InOrder(root, nums, &count);
    return root;
}

```


