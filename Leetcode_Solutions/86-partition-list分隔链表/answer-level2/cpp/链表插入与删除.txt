### 解题思路
记录最近小于x的节点位置,找到小于x的节点时，插入并更新

### 代码

```cpp
class Solution {
public:
    // 记录最近小于x的节点位置,找到小于x的节点时，插入并更新
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessNode = NULL;
        ListNode *newHead = head;
        ListNode **pos = &head;
        
        ListNode *next = NULL;
        for (next = head; next; next = next->next) {
            if (next->val >= x) {
                break;
            }
            lessNode = next;
            pos = &next->next;
        }

        while (*pos) {
            if ((*pos)->val >= x) {
                pos = &(*pos)->next;
                continue;
            } else {
                // delete node.
                ListNode *deleted = *pos;
                *pos = deleted->next;

                // insert node.
                if (!lessNode) {
                    lessNode = deleted;
                    lessNode->next = head;
                    newHead = lessNode;
                } else {
                    deleted->next = lessNode->next;
                    lessNode->next = deleted;
                    lessNode = deleted;
                }
            }
        }

        return newHead;
    }
};
```