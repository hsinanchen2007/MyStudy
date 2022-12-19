合并两个链表的代价是len1+len2，这有点像石子合并问题（哈夫曼树），所以每次我们都把最短的两条链拿出来合并，一样用优先队列实现。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct node{
     ListNode *next;
     int len;
     node():len(0),next(NULL){}
     bool operator<(node x)const{
         return len<x.len;
     }
 };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {//这部分把	21，合并两个有序链表的代码转过来就好了  
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val>l2->val)swap(l1,l2);
        ListNode* l=l1;
        ListNode* l3=l1;
        l1=l1->next;
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL||(l2!=NULL&&l1->val>l2->val)){
                l3->next=l2;
                l2=l2->next;
            }
            else{
                l3->next=l1;
                l1=l1->next;
            }
            l3=l3->next;
        }
        return l;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        priority_queue<node>q;
        for(int i=0;i<lists.size();i++){
            ListNode *x;
            node n;
            x=n.next=lists[i];
            while(x!=NULL){
                n.len++;
                x=x->next;
            }
            q.push(n);
        }
        for(int i=1;i<lists.size();i++){
            node x=q.top();q.pop();
            node y=q.top();q.pop();
            x.next=mergeTwoLists(x.next,y.next);
            x.len+=y.len;
            q.push(x);
        }
        ListNode *x=q.top().next;
        return x;
    }
};
```

