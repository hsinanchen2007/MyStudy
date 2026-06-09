### 解题思路
首先计数，第二次循环删除
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        int i = 0;
        while(p != nullptr){
            i++;
            p = p->next;
        }
        if(i == n) return head->next;
        for(int j = 1; j <= i; j++){
            if(j == i-n){
                q->next = q->next->next;
                break;
            }else{
                q = q->next;
            }
        }
        return head;
    }
};
```