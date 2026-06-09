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
    //反转链表
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if(head==nullptr) return res;
        ListNode* a=nullptr;
        ListNode* node=head;
        ListNode* phead=head;
        while(phead!=nullptr)
        {
            node=phead->next;//将phead->next存起来
            phead->next=a;
            a=phead;
            phead=node;
        }
        while(a!=nullptr)
        {
            res.push_back(a->val);
            a=a->next;
        }
        return res;


    }
};
```