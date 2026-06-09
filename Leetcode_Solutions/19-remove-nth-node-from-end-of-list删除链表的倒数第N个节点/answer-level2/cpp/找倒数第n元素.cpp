### 解题思路
重要的是找到倒数第n个元素，某一元素的正数排位与倒数排位之和等于元素的个数加一；
可设置快慢指针，快指针先指向正数第n+1元素，慢指针从head开始遍历，快指针从当前位置开始遍历，当快指针为空时，及找到倒数第n元素

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head,*p;
         if(head->next==NULL)
           return NULL;
        while(n>0)
        {  
            n--;
            fast=fast->next;
        }
        
        if(fast==NULL)
           return head->next;
        if(fast!=NULL)
        {
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        p=slow->next;
        slow->next=p->next;
        return head;
        }return NULL;

    }
};
```