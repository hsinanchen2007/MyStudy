### 解题思路
按照进阶要求:一次线性扫描

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
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        vector<ListNode*> list;
        ListNode* _head=head;

        while(head) list.push_back(head),head=head->next;
        n=list.size()-n;

        if(n>0)
        {
            list[n-1]->next=list[n]->next;
            delete list[n];
            return _head;
        }
        
        if(_head) _head=_head->next;
        else _head=NULL;
        delete list[0];
        return _head;
    }
};
```