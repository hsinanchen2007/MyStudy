### 解题思路
关键点：
1. 根据len/k和len%k分别获取每段链表至少所含节点的个数和前几段链表需要补齐节点的个数
2. 每段链表的结束必须置NULL，空链表除外

运行结果：
执行用时 :4 ms, 在所有 c 提交中击败了94.62%的用户
内存消耗 :7.6 MB, 在所有 c 提交中击败了100.00%的用户
### 代码

int GetListLen(struct ListNode *root)
{
    struct ListNode *tmp = root;
    int len = 0;
    while (tmp) {
        tmp = tmp->next;
        len++;
    }

    return len;
}

struct ListNode **splitListToParts(struct ListNode *root, int k, int *returnSize)
{
    int len = GetListLen(root);
    int width = len / k;
    int res = len % k;
    struct ListNode *prev = NULL;
    struct ListNode *curr = root;
    struct ListNode **retList = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);

    for (int i = 0; i < k; i++) {
        prev = curr;
        /* 根据len%k的结果判断前几个是否需要补齐一个节点 */
        for (int j = 0; j < width + (i < res ? 1 : 0) - 1; ++j) {
            if (curr != NULL) {
                curr = curr->next;
            }
        }
        /* 该段链表结束置NULL，并获取下一段链表起点 */
        if (curr != NULL) {
            struct ListNode *temp = curr;
            curr = curr->next;
            temp->next = NULL;
        }
        retList[i] = prev;
    }

    *returnSize = k;
    return retList;
}

```