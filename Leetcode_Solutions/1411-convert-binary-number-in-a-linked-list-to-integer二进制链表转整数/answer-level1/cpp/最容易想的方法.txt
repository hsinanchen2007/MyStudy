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
    int getDecimalValue(ListNode* head) {
        int t=0;
        ListNode* p=head;
        while(p!=NULL){
            t*=2;
            t+=p->val;
            p=p->next;
        }
        return t;
    }
};
```