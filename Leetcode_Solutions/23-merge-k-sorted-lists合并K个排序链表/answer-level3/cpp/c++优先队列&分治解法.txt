### 解题思路
实际优先队列竟然时间空间都比分治块emmm

### 代码
优先队列
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
        priority_queue<pair<int,ListNode*> ,vector<pair<int,ListNode*> >,greater<pair<int,ListNode*> > >q;
        for(auto i:lists){
            if(i!=NULL)
                q.push(make_pair(i->val,i));
        }
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        while(!q.empty()){
            auto tmp=q.top();
            q.pop();
            tail->next=tmp.second;
            tail=tail->next;
            if(tmp.second->next){
                q.push(make_pair(tmp.second->next->val,tmp.second->next));
            }
            tail->next=NULL;
        }
        return head->next;
    }
};
```
分治
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
    ListNode* ssort(ListNode* a,ListNode* b){
        if(a==NULL&&b==NULL)
            return NULL;
        ListNode* head=new ListNode(-1);
        ListNode* tail=head;
        while(a!=NULL&&b!=NULL){
            if(a->val>b->val){
                tail->next=b;
                tail=tail->next;
                b=b->next;
            }
            else{
                tail->next=a;
                tail=tail->next;
                a=a->next;
            }
        }
        while(a!=NULL){
            tail->next=a;
            tail=tail->next;
            a=a->next;
        }
        while(b!=NULL){
            tail->next=b;
            tail=tail->next;
            b=b->next;
        }
        tail->next=NULL;
        return head->next;
    }
    ListNode* solve(vector<ListNode*>& lists,int l,int r){
        if(l==r)
            return lists[l];
        if(r==l+1){
            return ssort(lists[l],lists[r]);
        }
        else{
            int mid=(l+r)>>1;
            return ssort(solve(lists,l,mid),solve(lists,mid+1,r));
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        return solve(lists,0,lists.size()-1);
    }
};
```