### 解题思路
此处撰写解题思路
暴力取值排序就完事了
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
        ListNode* dummy=new ListNode(0);
        ListNode* l=dummy;
        vector<int> v;
        for(ListNode* node:lists){
            while(node!=NULL){
                v.push_back(node->val);
                node=node->next;
            }
        }
        sort(v.begin(),v.end());
        for(int i:v){
            ListNode* t=new ListNode(i);
            l->next=t;
            l=l->next;
        }
        return dummy->next;
    }
};
```