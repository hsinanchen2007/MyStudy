### 解题思路
此处撰写解题思路
分治法，和归并排序类似
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
        int n=lists.size();
        if(n==0) return NULL;
        return merge(lists,0,n-1);
    }
    ListNode*merge(vector<ListNode*>& lists,int begin,int end){
        if(begin==end) return lists[begin];
        else{
            int mid=begin+end>>1;
            ListNode* l1=merge(lists,begin,mid);
            ListNode* l2=merge(lists,mid+1,end);
            ListNode* dummy=new ListNode(-1);
            ListNode* cur=dummy;
            while(l1 && l2){
                if(l1->val < l2->val){
                    cur->next=l1;
                    l1=l1->next;
                }else{
                    cur->next = l2;
                    l2=l2->next;
                }
                cur=cur->next;
            }
            cur->next=l1 ? l1 : l2;
            return dummy->next;
        }
    }
};
```