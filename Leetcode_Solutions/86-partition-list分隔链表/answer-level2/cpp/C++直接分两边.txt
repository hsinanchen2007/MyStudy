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
    ListNode* partition(ListNode* head, int target) {
        ListNode *small=new ListNode(-1);
        ListNode *big=new ListNode(-1);
        ListNode *res=small,*mid=big;
        while(head!=NULL){
            if(head->val<target){
                small->next=head;
                small=small->next;
            }
            else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }
        big->next=NULL;//若最后为小，则必须将big的next转移掉
        small->next=mid->next;
        return res->next;
    }
};
```