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
    ListNode* middleNode(ListNode* head) {
        bool flag=false;
        ListNode* p;
        ListNode* q;
        p=head;
        q=head;
        while(q!=NULL){
            if(flag){
                p=p->next;
            }
            q=q->next;
            flag=!flag;            
        }
        return p;
    }
};
```