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
    vector<int> reversePrint(ListNode* head) {
        //改变链表结构
        vector<int> res;
        ListNode* p=head;
        ListNode* node=head;
        ListNode* n=nullptr;
        while(p!=nullptr)
        {
           node=p->next;
           p->next=n;
           n=p;
           p=node;
        }
        while(n!=nullptr)
        {
            res.push_back(n->val);
            n=n->next;
        }
return res;
    }
};
```