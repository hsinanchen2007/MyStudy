### 解题思路
采用归并排序的方法


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * Merge(struct ListNode*list1,struct ListNode*list2){
    struct ListNode *l3,*r,*s;
    struct ListNode *l1,*l2;
    l1=list1;
    l2=list2;
    if(l1==NULL&&l2==NULL)return NULL;
    if(l1==NULL&&l2!=NULL)return l2;
    if(l1!=NULL&&l2==NULL)return l1;
    l3=(struct ListNode *)malloc(sizeof(struct ListNode));
    l3->next=NULL;
    if(l1->val>l2->val){
        l3->val=l2->val;
        l2=l2->next;
    }
    else{
        l3->val=l1->val;
        l1=l1->next;
    }
    r=l3;
    while(l1&&l2){
        if(l1->val>l2->val){
            s=(struct ListNode *)malloc(sizeof(struct ListNode));
            s->next=NULL;
            s->val=l2->val;
            l2=l2->next;
            r->next=s;
            r=r->next;
        }
        else{
            s=(struct ListNode *)malloc(sizeof(struct ListNode));
            s->next=NULL;
            s->val=l1->val;
            l1=l1->next;
            r->next=s;
            r=r->next;
        }
    }
    while(l1){
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        s->next=NULL;
        s->val=l1->val;
        l1=l1->next;
        r->next=s;
        r=r->next;
    }
    while(l2){
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        s->next=NULL;
        s->val=l2->val;
        l2=l2->next;
        r->next=s;
        r=r->next;
    }
    l1=list1;
    while(l1){
        list1=l1->next;
        free(l1);
        l1=list1;
    }
    l2=list2;
    while(l2){
        list2=l2->next;
        free(l2);
        l2=list2;
    }
    return l3;
}
struct ListNode *MergeT(struct ListNode**lists,int low,int high){
    int mid=(low+high)/2;
    struct ListNode *l1,*l2;
    if(low==high)return lists[low];
    l1=MergeT(lists,low,mid);
    l2=MergeT(lists,mid+1,high);
    return Merge(l1,l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)return NULL;
    struct ListNode *r;
    r=MergeT(lists,0,listsSize-1);
    return r;
}
```