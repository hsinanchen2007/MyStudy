### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
6.7 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

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
       if(head==NULL||head->next==NULL)
            return head;
       ListNode* L=head->next;
       ListNode* firstnode;
       ListNode* secondnode;
       ListNode* tepnode;
       ListNode* pnode=NULL;
       firstnode=head;
       secondnode=head->next;
       while(firstnode!=NULL&&firstnode->next!=NULL)
       {
            if(pnode!=NULL)
                pnode->next=secondnode;
            tepnode=secondnode->next;
            firstnode->next=secondnode->next;
            secondnode->next=firstnode;
            pnode=firstnode;
            firstnode=tepnode;
            if(firstnode)
                secondnode=firstnode->next;
            
       }
       return L;
    }
};
```