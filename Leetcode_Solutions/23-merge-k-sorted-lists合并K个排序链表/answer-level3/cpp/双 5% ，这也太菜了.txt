### 解题思路
将初始链表分为两半，直到只剩两个链表 ，开始排序
递归。。。。
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
 /* 分治 +递归 */
ListNode* binarymerge(vector<ListNode* > lists,int start,int end);
ListNode* mergeTwoList(ListNode *p,ListNode *q);

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return binarymerge(lists,0,lists.size()-1);
    }
};

ListNode* binarymerge(vector<ListNode* > lists,int start,int end)
{
    if(end==start) return lists[start];
    if(end-start==1){
        return mergeTwoList(lists[start],lists[end]);
    }
    int mid=(start+end)/2;
    ListNode*m= binarymerge(lists,start,mid);
    ListNode*n=binarymerge(lists,mid+1,end);
    return mergeTwoList(m,n);
}

ListNode* mergeTwoList(ListNode *p,ListNode *q)
{
    ListNode* head=new ListNode;//(ListNode*)(new char[16]);//////////new
    ListNode* tmp=head;
    while(p||q){
        while(p&&q){
            if(p->val <= q->val){
                tmp->next=p;
                tmp=p;
                p=p->next;
            }
            else{
                tmp->next=q;
                tmp=q;
                q=q->next;
            }
        }
        while(!p&&q){
            tmp->next=q;
            tmp=q;
            q=q->next;
        }
        while(!q&&p){
            tmp->next=p;
            tmp=p;
            p=p->next;
            
        }
        tmp->next=NULL;
    }
    return head->next;
}
```