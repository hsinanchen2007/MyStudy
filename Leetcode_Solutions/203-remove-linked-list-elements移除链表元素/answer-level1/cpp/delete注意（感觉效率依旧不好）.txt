### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了36.24% 的用户
内存消耗 :13.5 MB, 在所有 C++ 提交中击败了5.19%的用户


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
 //第一种
 //设置哨兵+两个指针，一个指向dummy，一个指向head
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy ;
        ListNode* cur ;
        for(cur = head ; cur != nullptr ;  )//cur = cur->next不能加在后面，因为下面会把这块内存delete掉
        {
            if(cur->val == val)
            {
                ListNode* temp = cur;
                pre->next = cur->next;
                cur = cur->next;
                //先把地址cur确定了，再让temp去delete原先cur的内存
                delete temp;
                temp = nullptr;
            }
            else
            {
                 pre = pre->next;
                 cur = cur->next;
            }
           
        }
        return dummy->next;
    }
};
```