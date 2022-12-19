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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* ans=head->next;//初始化（交换前两个节点）
        head->next=ans->next;
        ans->next=head;

        ListNode* p1=ans->next;
        ListNode* p2=p1->next;
        while(p2!=nullptr && p2->next!=nullptr){
            p1->next=p1->next->next;
            p2->next=p1->next->next;
            p1->next->next=p2;
            p1=p2;
            p2=p1->next;
        }
        return ans;
    }
};
```