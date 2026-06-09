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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int a[100000]={0};
        int len=0;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]!=NULL){
                a[len++]=lists[i]->val;
                lists[i]=lists[i]->next;
            }
        }
        sort(begin(a),begin(a)+len);
        ListNode* head=new ListNode(-1);
        ListNode* x=head;
        for(int i=0;i<len;i++)
        {
            x->next=new ListNode(a[i]);
            x=x->next;
        }
        return head->next;
    }
};
```