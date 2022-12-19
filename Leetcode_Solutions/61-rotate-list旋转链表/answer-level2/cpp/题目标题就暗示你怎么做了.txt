### 解题思路
这题目的名字真好，旋转链表，不是右移链表，很自然会想到先把链表变成环形，再视情况剪掉一条边就可以了。

### 代码

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ptr = head;
        if (NULL == head || NULL == head->next) return head;
        int size = 0;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            size++;
        }
        size += 1;
        ptr->next = head;
        k = k % size;
        for (int i=0; i<size-k; i++) {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};
```