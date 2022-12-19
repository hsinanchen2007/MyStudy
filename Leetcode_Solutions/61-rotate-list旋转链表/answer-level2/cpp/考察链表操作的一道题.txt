### 解题思路
只需要先构建环，再根据长度推算出需要移动多少次

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;

        ListNode * tmp = head;
        ListNode * h = head;
        int len = 0;

        // 计算出长度
        while (tmp != NULL)
        {
            len++;

            if (tmp->next == NULL)
            {
                tmp->next = h;
                tmp = tmp->next;
                break;
            }

            tmp = tmp->next;
        }

        if (len == 0)
            return head;

        int moveCount = len - (k % len);
        if (moveCount < 0)
            moveCount = k % len;

        // 注意当len小于k的时候取绝对值

        while (moveCount > 1)
        {
            tmp = tmp->next;
            moveCount--;
        }

        h = tmp->next;
        tmp->next = NULL;

        return h;
    }
};
```