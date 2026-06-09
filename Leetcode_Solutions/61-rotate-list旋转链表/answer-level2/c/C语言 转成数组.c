### 解题思路
操作线性数组会更方便一些，不过性能确实下降了，毕竟多了一次遍历
![image.png](https://pic.leetcode-cn.com/b30755f4df98c13e8d7985a7945e43939710f56c2eee641fa19d14e18325e6f3-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int lCnt(struct ListNode* head)
{
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}
struct ListNode* lrotate(struct ListNode* head, int n, int k)
{
    int i;
    struct ListNode **arr = NULL;
    struct ListNode *newHead = NULL;
    struct ListNode *newTail = NULL;
    arr = (struct ListNode**)calloc(n, sizeof(struct ListNode*));
    if (arr == NULL) {
        printf("lrotate arr == NULL\n");
        return NULL;
    }
    for (i = 0; i < n; i++) {
        arr[i] = head;
        head = head->next;
    }
    newHead = arr[n-k];
    newTail = arr[n - k - 1];
    newTail->next = NULL;
    arr[n - 1]->next = arr[0];
    free(arr);
    return newHead;
}
struct ListNode* rotateRight(struct ListNode* head, int k){
    int n;
    n = lCnt(head);
    if (n == 0) {
        return head;
    }
    k %= n;
    if (k == 0) {
        return head;
    }
    return lrotate(head, n, k);
}
```