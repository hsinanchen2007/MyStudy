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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        ListNode* temp;
        if(head1->val<head2->val){
            temp=head1;
            head1=head1->next;
        }else{
            temp=head2;
            head2=head2->next;
        }
        temp->next=merge(head1,head2);
        return temp;
    }
    ListNode* mergeByBinary(vector<ListNode*>& lists,int left,int right){
        if(left>right) return NULL;
        if(left==right){
            return lists[left];
        }
        int p=(left+right)/2;
        ListNode* l=mergeByBinary(lists,left,p);
        ListNode* r=mergeByBinary(lists,p+1,right);
        return merge(l,r);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeByBinary(lists,0,lists.size()-1);
    }
};
```