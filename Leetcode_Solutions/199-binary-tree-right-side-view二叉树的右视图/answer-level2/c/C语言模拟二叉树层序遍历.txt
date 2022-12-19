### 解题思路
这题其实就是找出二叉树每一层的最右边的那个元素，那么我们就可以模拟二叉树的层序遍历。
具体实现见代码注释

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

int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int) * 500);
    struct TreeNode *Queue[10000];
    int front, last, rear;

/* front指向队列头（即出队元素）last指向该层的尾部，rear实时更新尾部 */
    front = rear = 0;
    
    Queue[root ? rear++ : rear] = root;
    last = rear;
    
    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        
/* 每次一个元素出队时，就将它的儿子添加到下一层的队列中 */
        if (p->left)
            Queue[rear++] = p->left;
        if (p->right)
            Queue[rear++] = p->right;
        
/* 当前元素到了该层的尾部，取出我们想要的元素，然后更新last为下一层的尾部 */
        if (front == last) {
            res[(*returnSize)++] = Queue[last - 1]->val;
            last = rear;
        }
    }
    
    return res;
}
```