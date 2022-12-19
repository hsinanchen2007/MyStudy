### 解题思路
1. 检测检测链表是否有循环：使用快慢指针。
2. 找出循环开始的位置。
![image.png](https://pic.leetcode-cn.com/21c862d0df3ea6f5eb3f3758d3cfc54d1ad8e44f87d83d96c42487e203cf6ec9-image.png)
令 A 为头结点，B 为循环开始的位置，C 为快指针和慢指针相遇的地方。
则快指针经历 A-B-C，长度为 L1；慢指针经历 A-B-C-B-C，长度为 L2。
L2 = 2 * L1，所以 A-B-C 的长度等于 C-B-C 的长度，
所以 A-B 的长度等于 C-B 的长度。

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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        // 检测检测链表是否有循环
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                cycle = true;
                break;
            }
        }

        if(!cycle)
        {
            return nullptr;
        }

        // 找出循环开始的位置
        ListNode* p = head;
        while(p != fast)
        {
            p = p->next;
            fast = fast->next;
        }
        return p;
    }
};
```
