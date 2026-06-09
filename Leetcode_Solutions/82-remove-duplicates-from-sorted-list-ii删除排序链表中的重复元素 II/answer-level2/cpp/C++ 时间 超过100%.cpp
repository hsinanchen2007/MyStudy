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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* dump = new ListNode(-1);

        dump -> next = head;
        ListNode *pre = dump, *tem = dump -> next;
        bool isthelist = false;
        while(tem != NULL && tem -> next != NULL)
        {
            
            if(tem ->val == tem -> next -> val)
            {
                tem = tem ->next;
                isthelist = true;
                continue;
            }
            if(!isthelist)
            {
                tem = tem -> next;
                pre = pre -> next;
            }
            else
            {
                tem = tem -> next;
                pre -> next =tem;
                isthelist = false;
            }     
        } 

        if(pre -> next != tem) pre -> next = tem -> next;
        return  dump -> next;
    }
};
```