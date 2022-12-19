### 解题思路
不得不感叹真的太聪明了，2倍速度就是正好能卡在相遇的点，别的倍数就不行。

### 代码

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        if (NULL==head) return NULL;
        while (true) {
            if (NULL==fastPtr->next || NULL==fastPtr->next->next) return NULL;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if (slowPtr==fastPtr) break;
        }
        slowPtr = head;
        while (slowPtr != fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }
};
```