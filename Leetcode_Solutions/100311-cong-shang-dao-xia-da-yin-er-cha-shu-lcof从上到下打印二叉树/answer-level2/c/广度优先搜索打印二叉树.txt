题目`提示：节点总数<=1000`，但实际打印节点个数超越了$1000$。
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
int* levelOrder(struct TreeNode* root, int* returnSize){
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode* q[1001]; // 队列 (实际用不了这么多空间)
    int head = 0, tail = 0; // head指向队首元素，tail指向队尾元素之后的空位置

    q[tail++] = root;

    int arr[1200]; // 暂存打印的二叉树节点的值
    int p = 0;

    while(head != tail){
        struct TreeNode* node = q[head++];
        head %= 1001;

        arr[p++] = node->val;

        if(node->left != NULL){
            q[tail++] = node->left;
            tail %= 1001;
        }
        if(node->right != NULL){
            q[tail++] = node->right;
            tail %= 1001;
        }
    }
    *returnSize = p;
    int* result = (int*)malloc(p * sizeof(int));
    memcpy(result, arr, p * sizeof(int));
    return result;
}
```
