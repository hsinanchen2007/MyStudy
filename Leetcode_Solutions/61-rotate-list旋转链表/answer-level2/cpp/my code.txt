### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了97.06%的用户
内存消耗 :6.4 MB, 在所有 C++ 提交中击败了100.00%的用户
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
        if (!head || !head->next || k <= 0)
            return head;
        
        ListNode* cur = head;
        int i = k;
        int count = 0;
        while (cur && i-- > 0) {
            cur = cur->next;
            count++;
        }

        if (i > 0) {
            // k大于list长度, k % count取模，再重新算
            if (0 == count)
                return head;
            k = k % count;
            if (0 == k)
                return head;
            cur = head;
            while (cur && k-- > 0) {
                cur = cur->next;
            }
        }
        
        // 不用旋转
        if (!cur && i == 0){
            return head;
        }

        // cur不为null，即k小于list长度，找到位置，切换就好
        ListNode* slow = head;
        ListNode* tail = cur;
        while (tail->next){
            tail = tail -> next;
            slow = slow -> next;
        }

        tail->next = head;
        ListNode* newHead = slow->next;
        slow->next = NULL;
        return newHead;
    }
};
```