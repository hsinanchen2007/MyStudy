### 解题思路
        // step_fast = 2 * step_slow;
        // if: meet_point = cycle_head + m
        // head to cycle_head = step_slow - m.
        // meet_point to cycle_head = step_slow - m. (may n* cycle)

### 代码

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        // has cycle.
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (!fast || !fast->next) {
            return nullptr;
        }

        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

```