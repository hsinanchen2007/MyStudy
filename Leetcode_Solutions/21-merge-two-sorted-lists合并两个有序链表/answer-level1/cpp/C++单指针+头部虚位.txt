### 解题思路
这一题好像不用迭代，会有更好的时间复杂度

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(0);
        ListNode* p=res;
        while (l1!=NULL || l2!=NULL) {
            if (((l1!=NULL && l2!=NULL)&&(l1->val < l2->val)) || (l1!=NULL && l2==NULL)) {
                p->next=l1;
                l1=l1->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        return res->next;
    }
};
```