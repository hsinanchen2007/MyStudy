### 解题思路
![image.png](https://pic.leetcode-cn.com/b9cae384c76d9c01944cf0e84e7ab85bdb63abce06d8b7b397b01129e5ce2f5a-image.png)
1、思路很明显，需要先找到m前面的那个节点，为了首节点的处理，需要设置哑巴节点
2、另外处理到最后一个的时候，需要注意空指针的判定。
3、这道题目只要思路明确，感觉难度还好。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) {
        return NULL;
    }

    int cnt = 0;
    struct ListNode *preHead = calloc(1, sizeof(struct ListNode));
    preHead->next = head;
    struct ListNode *first = preHead;
    head = preHead;

    while (cnt < m - 1) {
        cnt++;
        head = head->next;
    }
    first = head;

    struct ListNode *second = first->next;
    struct ListNode *tmp = NULL;
    struct ListNode *p = NULL;

    while (cnt <= n) {
        p = head->next;
        head->next = tmp;
        tmp = head;
        head = p;

        cnt++;
    }

    first->next = tmp;
    second->next = p;

    return preHead->next;
}
```