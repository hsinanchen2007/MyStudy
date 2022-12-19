### 解题思路
此处撰写解题思路
1. 如果没做反转，则head即返回；如果做了反转，则需要重定位head，重定位的head在第一组中最后一个结点
2. 需要哨兵（游标）指针来往前K步进行探测；若哨兵能够在k步之内安全，则哨兵的非空next是下一次反转的头
3. 每次翻转过后，本次反转区段的末尾需要接上下一段的头，而上一次反转的段的末尾需要接上本段的头  即 last_end->next = prev; curr_start->next = next_start;
4. 


1->2->3->4->5->NULL  k = 2
1<-2  3->4->5->NULL     反转前，3是next_start; 反转后，1是curr_start, 所以需要把1接上

1<-2  3<-4  5->NULL     
|     ^  
|     |
------   






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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;

        auto* guard = head;
        auto* curr_start = head;
        auto* next_start = head;
        bool is_finished = false;
        ListNode* prev = nullptr;
        ListNode* re_head = nullptr;
        ListNode* last_end = nullptr;

        while (!is_finished) {
            curr_start = guard;

            for (int i=0; i<k-1; ++i) {

                if (guard == nullptr || guard->next == nullptr) {
                    is_finished = true;
                    break;
                }
                guard = guard->next;
            }

            if (guard == nullptr)
                break;

            guard = guard->next;

            if (!is_finished && re_head == nullptr) {
                re_head = head;
                for (int i=0; i<k-1; ++i) {
                    re_head = re_head->next;
                }

            }

            if (!is_finished) {
                next_start = guard;
                auto* curr = curr_start;
                
                while (curr != next_start) {
                    auto* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }

                curr_start->next = next_start;

                if (last_end != nullptr) {
                    last_end->next = prev;
                }

                last_end = curr_start;
            }
        }

        return re_head;
    }
};
```