### 解题思路
快慢指针法

1.只需要知道是否有环
设置快慢指针，slow、fast各走一步，判断链表是否有环，没有的话fast再走一步
快慢指针相等时即为有环

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //快慢指针
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast)
        {
            slow=slow->next;//slow走一步
            fast=fast->next;//fast走一步
            if(!fast)//没有环
            {
               return false;
            }
            fast=fast->next;//fast走一步
            if(slow==fast)
            {
               return true;
            }
        }
        return false;
    }
};
```

2.需要知道环的入口节点
设置快慢指针和相遇节点，slow、fast各走一步，判断链表是否有环，没有的话fast再走一步
快慢指针相等时设置相遇节点
head和meet同时遍历到一个点时即为环入口

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
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* meet=NULL;
        while(fast)
        {
            slow=slow->next;
            fast=fast->next;
            if(!fast)
            {
                return NULL;
            }
            fast=fast->next;
            if(fast==slow)
            {
                meet = fast;
                break;
            }
            
        }
        if(meet == NULL)
            {
                return  NULL;
            }
            while(head&&meet)
            {
                if(head==meet)
                {
                    return head;
                }
                head=head->next;
                meet=meet->next;
            }
            return NULL;

    }
};
```