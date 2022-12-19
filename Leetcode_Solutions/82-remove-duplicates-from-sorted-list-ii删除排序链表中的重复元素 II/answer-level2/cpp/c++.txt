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
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* start = newhead;
        ListNode* j = start->next;
        int cnt = 0;
        while(j){
            if(j->val == start->next->val){
                ++cnt;
                j = j->next;
            }
            else{
                //start = start->next;
                if(cnt >= 2){
                    start->next = j;
                    cnt = 0;
                }else{
                    start = start->next;
                    cnt = 0;
                }
            }
        }
        if(cnt >= 2)start->next = j;
        return newhead->next;
    }
};
```