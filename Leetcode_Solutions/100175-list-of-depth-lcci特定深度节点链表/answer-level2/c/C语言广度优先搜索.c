### 解题思路
本题稍微麻烦点的地方在于需要将每层的节点串成一个新链表，用于返回，详细见注释

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void BFS(struct ListNode **retArr, struct TreeNode **queue, int start, int end, int *returnSize)
{
    int qLen = end - start;
    int i;
    int startFlag = start;
    int endFlag = end;
    // 如果队列长度为0则返回
    if (qLen == 0) {
        return;
    }
    // 为该层待返回链表申请空间
    retArr[(*returnSize)] = (struct ListNode *)malloc(sizeof(struct ListNode) * qLen);
    // 拷贝第一个链表节点
    memcpy(&retArr[(*returnSize)][0], queue[start], sizeof(struct ListNode));
    for (i = 1; i < qLen; i++) {
        // 依次拷贝剩余链表节点，并将上一个链表的next指向此节点
        memcpy(&retArr[(*returnSize)][i], queue[start + i], sizeof(struct ListNode));
        retArr[(*returnSize)][i - 1].next = &(retArr[(*returnSize)][i]);
    }
    // 要将该层最后一个节点的next置为NULL，不然会指到别的节点上
    retArr[(*returnSize)][qLen - 1].next = NULL;
    // 层次++
    (*returnSize)++;
    // 清除该层节点并将该层每个节点的子节点入队
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
    BFS(retArr, queue, start, end, returnSize);
    
    return;
}

struct ListNode** listOfDepth(struct TreeNode *tree, int *returnSize){
    *returnSize = 0;
    if (tree == NULL) {
        return NULL;
    }
    // 为待返回的数据申请内存
    struct ListNode **retArr = (struct ListNode **)malloc(sizeof(struct ListNode *) * 1000);
    // 创建一个树节点数组用于代替队列
    struct TreeNode *queue[1000] = {{ 0 }};
    int start, end;
    // 根节点入队
    queue[0] = tree;
    start = 0;
    end = 1;
    // 广度优先搜索
    BFS(retArr, queue, start, end, returnSize);

    return retArr;
}
```