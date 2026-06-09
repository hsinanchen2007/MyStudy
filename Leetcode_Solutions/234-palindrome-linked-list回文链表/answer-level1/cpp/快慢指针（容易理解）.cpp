### 解题思路
此处撰写解题思路

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
    bool isPalindrome(ListNode* head) {
        //特殊性判断
        if(head == nullptr || head->next == nullptr)return true;

        //使用快慢指针来获得中间结点
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //反转以slow为头指针的后面链表
        ListNode* slow_head = slow;
        while(slow->next != nullptr)
        {
            ListNode* temp = slow->next;
            slow->next = temp->next;
            temp->next = slow_head;
            slow_head = temp;
        }

        //链表的前半部分社后半部分比较
        while(slow_head != nullptr)
        {
            if(slow_head->val != head->val)
            return false;
            head = head->next;
            slow_head = slow_head->next;
        }
        return true;

    }
};
```