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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* list=new ListNode(0);
    ListNode*tmp=list;
    vector<int> v;
    while(l1)
    {
        v.push_back(l1->val);
        l1=l1->next;
    }
    while(l2)
    {
        v.push_back(l2->val);
        l2=l2->next;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        ListNode* node= new ListNode(v[i]);
        tmp->next=node;
        tmp=tmp->next;
    }
    return list->next;
    }
};
```
  ListNode *dummy = new ListNode(0);//这个是一个题解中一个大神写的，很简练，很厉害。
    ListNode *cur = dummy;
    while(l1 && l2)
    {
        if(l1->val <l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 :l2;//处理l1或者l2有剩余的情况
    return dummy->next;