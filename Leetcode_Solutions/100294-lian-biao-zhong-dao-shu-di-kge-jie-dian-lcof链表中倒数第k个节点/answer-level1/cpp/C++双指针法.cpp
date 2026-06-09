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
//双指针法
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==nullptr||k<=0) return nullptr;
        ListNode* a=head;
        ListNode* b=head;
        for(int i=1;i<k;i++)//b比a多走k-1
        {
            b=b->next;
        }
        while(b->next!=nullptr)
        {
            b=b->next;
            a=a->next;
        }
        return a;

    }
};
```