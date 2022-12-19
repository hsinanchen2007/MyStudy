## 思路
1. 先统计链表节点个数
2. 计算从前向后移动步数

### 代码

```cpp
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int cnt = 0;
        ListNode *cur = head;
        while (cur) {
            ++cnt;
            cur = cur->next;
        }
        int move = cnt - k;
        while (move--) {
            head = head->next;                                    
        }
        return head;
    }
};
```