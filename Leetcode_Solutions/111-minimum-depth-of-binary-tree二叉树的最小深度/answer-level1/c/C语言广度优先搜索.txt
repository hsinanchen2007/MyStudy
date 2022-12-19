### 解题思路
利用数组模拟队列，用start和end指针标记队头队尾，入队出队通过移动start和end实现

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
void BFS(int *retMin, int parLevel, struct TreeNode **queue, int start, int end)
{
    int level = parLevel + 1;
    // 入队出队会改变start和end值，需要记录下来
    int startFlag = start;
    int endFlag = end;
    int i;
    int qLen = end - start;
    // 如果队列长度为0，则返回
    if (qLen == 0) {
        return;
    }
    // 层次遍历，将现有队列中的所有节点的子节点入队，现有节点出队，在此期间计算叶子节点的层数并记录最小值
    for (i = startFlag; i < endFlag; i++) {
        // 左子树入队
        if (queue[i]->left != NULL) {
            queue[end++] = queue[i]->left;
        }
        // 右子树入队
        if (queue[i]->right != NULL) {
            queue[end++] = queue[i]->right;
        }
        // 计算叶子节点的深度并记录最小值
        if (queue[i]->left == NULL && queue[i]->right == NULL) {
            if (level < *retMin) {
                *retMin = level;
            }
        }
        start++;
    }
    // 继续广度优先遍历
    BFS(retMin, level, queue, start, end);
    return;

}

int minDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    // 用于模拟队列的数组
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
    queue[0] = root;
    int start = 0;
    int end = 1;
    // 设一个大一点的值以便后续比较
    int retMin = 10000;
    // 广度优先遍历
    BFS(&retMin, 0, queue, start, end);
    return retMin;
}
```