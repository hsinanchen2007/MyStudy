### 解题思路
关键在于使用数组模拟队列，装一层，记一层，删一层再装下一层

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
void BFS(struct Node **queueArr, int start, int end, int *ret)
{
    int queueLen = end - start;
    int i, j;
    int startFlag = start;
    int endFlag = end;
    // 队列长度为0则返回
    if (queueLen == 0) {
        return;
    }
    // 否则代表层数要++
    (*ret)++;
    // 清空该层的同时将该层节点的子节点装入队列
    for (i = startFlag; i < endFlag; i++) {
        if (queueArr[i]->numChildren > 0) {
            for (j = 0; j < queueArr[i]->numChildren; j++) {
                // 子节点入队
                queueArr[end++] = (queueArr[i]->children)[j];
            }
        }
        // 相当于出队
        start++;
    }
    // 继续广度优先
    BFS(queueArr, start, end, ret);
    return;
}

int* maxDepth(struct Node* root) {
    int ret = 0;
    if (root == NULL) {
        return ret;
    }
    // 用于代替队列的数组，存储节点
    struct Node *queueArr[10000] = { { 0 } };
    // 用例模拟入队出队的下标
    int start, end;
    // 根节点入队
    queueArr[0] = root;
    start = 0;
    end = 1;
    // 广度优先搜索
    BFS(queueArr, start, end, &ret);

    return ret;
}
```