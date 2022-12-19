### 解题思路
双百，广度优先搜索，数组模拟队列，详细见注释

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
void BFS(struct TreeNode **queue, int start, int end, int x, int y, bool *ret)
{
    int i, j;
    int startFlag = start;
    int endFlag = end;
    int qLen = end - start;
    if (qLen == 0) {
        return;
    }
    
    for (i = start; i < end; i++) {
        // 如果在同一层中能够找到这两个目标数字，则将返回值置为true
        if (queue[i]->val == x) {
            for (j = start; j < end; j++) {
                if (queue[j]->val == y) {
                    *ret = true;
                }
            }
        }
        // 这里是为了防止这两个数字共父节点
        if (queue[i]->left != NULL && queue[i]->right != NULL) {
            if (queue[i]->left->val == x && queue[i]->right->val == y) {
                return;
            }
            if (queue[i]->right->val == x && queue[i]->left->val == y) {
                return;
            }
        }
    }
    // 移除该层，填入下一层
    for (i = startFlag; i < endFlag; i++) {
        if (queue[i]->left != NULL) {
            queue[end++] = queue[i]->left;
        }
        if (queue[i]->right != NULL) {
            queue[end++] = queue[i]->right;
        }
        start++;
    }
    // 继续广度优先搜索
    BFS(queue, start, end, x, y, ret);
    return;
}

bool isCousins(struct TreeNode* root, int x, int y){
    bool ret = false;
    // 用于模拟队列的数组
    struct TreeNode* queue[1000] = { { 0 } };
    int start, end;
    // 第一个元素入队
    queue[0] = root;
    start = 0;
    end = 1;
    // 广度优先搜索
    BFS(queue, start, end, x, y, &ret);

    return ret;
}
```