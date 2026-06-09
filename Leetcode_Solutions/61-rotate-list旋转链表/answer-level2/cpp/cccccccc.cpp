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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)return head;     
        int n = 0;
        for(auto p = head;p;p=p->next)++n;    
        k %= n;
        ListNode* first = head;
        ListNode* second = head;
        while(k--)second = second->next;
        while(second->next){
                first = first->next;
                second = second->next;
        }
        auto tmp = second->next;
        second->next = head;
        head = first->next;
        first->next = tmp;
        return head;
    }
};
```