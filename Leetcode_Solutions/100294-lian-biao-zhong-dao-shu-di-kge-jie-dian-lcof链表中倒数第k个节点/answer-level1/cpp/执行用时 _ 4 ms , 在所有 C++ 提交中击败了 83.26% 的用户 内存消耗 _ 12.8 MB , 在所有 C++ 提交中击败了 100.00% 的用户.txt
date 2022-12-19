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
        if(head == NULL){
            return NULL;
        }
        ListNode *pfast,*plow;
        pfast = plow = head;
        while(k--){
            pfast = pfast->next;
        }
        while(pfast){
            pfast=pfast->next;
            plow=plow->next;
        }
        return plow;
    }
};
```