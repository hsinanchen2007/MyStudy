### 解题思路
注意：当为偶数链表：1-2-3-4
反转位置是3：所以1>2>3<4;而3>null
所以前后链表的节点数不一致，遍历时候必须
while(head&&pre){//都要非空
            if(pre->val!=head->val) 
                return false;
            pre=pre->next;
            head=head->next;
        }

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
        if(!head) return true;
        ListNode* slow=head;
        ListNode* fast=head;
//找逆序点
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
//链表逆序
        ListNode*pre=nullptr;
        while(slow){
            ListNode*temp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=temp;
        }
        while(head&&pre){//都要非空
            if(pre->val!=head->val) 
                return false;
            pre=pre->next;
            head=head->next;
        }
        return true;
    }
};
```