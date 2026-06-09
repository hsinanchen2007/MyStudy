### 解题思路
分成两个链表，小于部分和大于等于部分(尾插法生成链表)，再将两个链表串起来

注意：可能存在为空的部分  如小于部分为空，或 大于等于部分为空

### 代码

```cpp

class Solution {
public:
    //保留两个分区中每个节点的初始相对位置
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* less_head = nullptr;
        ListNode* less_tail = nullptr;

        ListNode* more_equal_head = nullptr;
        ListNode* more_equal_tail = nullptr;

        ListNode* cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                if (less_head == nullptr)
                {
                    less_head = cur;
                    less_tail = cur;
                }
                else
                {
                    less_tail->next = cur;
                    less_tail = cur;
                }
            }
            else
            {
                if (more_equal_head == nullptr)
                {
                    more_equal_head = cur;
                    more_equal_tail = cur;
                }
                else
                {
                    more_equal_tail->next = cur;
                    more_equal_tail = cur;
                }
            }

            cur = cur->next;
        } 

        //置空
        if (more_equal_tail)
        {
            more_equal_tail->next = nullptr;
        }

        //串连两个链表
        if (less_tail) //小于区域存在
        {
            less_tail->next = more_equal_head;
            return less_head;
        }
        else //小于区域不存在
        {
            return more_equal_head;
        }
    }
};
```