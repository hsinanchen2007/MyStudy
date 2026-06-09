### 解题思路
此处撰写解题思路
快慢指针--第一个指针不变，慢指针赋值为第二个，快指针赋值为第三个，快慢指针相差一个。
使用尾插法，
ListNode *fast=head->next->next,*slow=head->next,*p=slow;
while(fast&&fast->next)
        {
            tail->next=fast;//奇数链表 尾插入
            tail=fast;
            slow->next=fast->next;//偶数链表 逻辑删除奇数结点

            slow=fast->next;
            fast=fast->next->next;
        }
    if(fast)//当结点为奇数时，快指针不为空
        {
            slow->next=nullptr;//偶数链表 逻辑删除奇数结点
            tail->next=fast;//奇数链表 尾插入
            tail=fast;
        }
        tail->next=p;//把偶数链表插入到奇数链表后面
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!(head->next->next))
            return head;
        ListNode *fast=head->next->next,*slow=head->next,*p=slow;
        head->next=NULL;
        ListNode* tail=head;
        while(fast&&fast->next)
        {
            tail->next=fast;
            tail=fast;
            slow->next=fast->next;
            slow=fast->next;
            fast=fast->next->next;
        }
        if(fast)
        {
            slow->next=nullptr;
            tail->next=fast;
            tail=fast;
        }
        tail->next=p;
        return head;
    }
};
```