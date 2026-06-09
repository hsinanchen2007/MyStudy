```

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
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* reTmp;
        if(l1->val > l2->val){// 设置l1为主链
            
            reTmp=l1;
            l1=l2;
            l2=reTmp;
        }
        ListNode *l1Ptr,*l1PtrPrev;
        ListNode *l2Ptr;
        
        l1Ptr = l1;
        l1PtrPrev = l1->next;
        l2Ptr = l2;
        
        // combine two list 
        while( l1PtrPrev!=NULL && l2Ptr!=NULL ){
            if(l2Ptr->val >= l1Ptr->val && l2Ptr->val <=l1PtrPrev->val){//向主链中插入l2
                l1Ptr->next=l2Ptr;
                l1Ptr=l2Ptr;
                reTmp=l2Ptr->next;
                l2Ptr->next=l1PtrPrev;
                l2Ptr=reTmp;
                continue;
            }
            if(l2Ptr->val >= l1PtrPrev->val){//主链后移
                // move step
                l1Ptr=l1PtrPrev;
                l1PtrPrev=l1PtrPrev->next;
            }
        } 
        if(l2Ptr==NULL){
            return l1;
        }
        if(l1PtrPrev==NULL){
            l1Ptr->next=l2Ptr;
            return l1;
        }
        return l1;
        
    }
};
```