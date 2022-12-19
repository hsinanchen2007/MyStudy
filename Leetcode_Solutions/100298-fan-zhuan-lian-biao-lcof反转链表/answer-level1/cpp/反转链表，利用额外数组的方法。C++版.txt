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
    ListNode* reverseList(ListNode* head) {
        int a[5010],index=0;
        ListNode* copy_head=head;
        ListNode* ans=head;
        while(head!=NULL){
            a[index++]=head->val;
            head=head->next;
        }
        for(int i=index-1;i>=0;--i){
            copy_head->val=a[i];
            copy_head=copy_head->next;
        }
         return ans;
    }
};
```