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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* tmp=head;
        int i=1;
        while(head->next!=NULL)
        {
            i++;
            head=head->next;
        }
        int j=i-k;
        for(int i=0;i<j;i++)
        {
            tmp=tmp->next;
        }
        return tmp;
    }
};
```