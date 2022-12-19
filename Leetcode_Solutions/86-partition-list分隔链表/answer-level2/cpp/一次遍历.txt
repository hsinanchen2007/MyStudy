### 解题思路
遇到第一个大的，则生成一个小值尾指针，后续遇到的小的，则插入到小值尾指针后面

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
    ListNode* partition(ListNode* head, int x) {
        if(x == INT_MIN)return head;
        ListNode* duan = new ListNode(x-1);
        duan->next = head;
        ListNode* pre = NULL;
        ListNode* cur = duan;
        while(cur->next)
        {
            if(cur->next->val < x )
            {
                if(pre){
                    ListNode* tmp = cur->next;
                    cur->next = tmp->next;
                    tmp->next = pre->next;
                    pre->next = tmp;
                    pre = pre->next;
                }
                else{
                    cur = cur->next;
                }
            }
            else
            {
                if(!pre)
                    pre = cur;
                cur = cur->next;
            }
        }
        return duan->next;
    }
};
```