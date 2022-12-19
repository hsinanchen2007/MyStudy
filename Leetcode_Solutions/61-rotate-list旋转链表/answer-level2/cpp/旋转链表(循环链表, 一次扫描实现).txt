### 解题思路
一次扫描链表,并保存,连成环,然后在合适位置断开

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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return NULL;

        vector<ListNode*> Nodes;
        ListNode* _head=head;

        while(head) 
        {
            Nodes.push_back(head);
            if(!head->next) break;
            head=head->next;
        }

        head->next=_head;
        int n=Nodes.size();

        Nodes[n-k%n-1]->next=NULL;
        return Nodes[(n-k%n)%n];
    }
};
```