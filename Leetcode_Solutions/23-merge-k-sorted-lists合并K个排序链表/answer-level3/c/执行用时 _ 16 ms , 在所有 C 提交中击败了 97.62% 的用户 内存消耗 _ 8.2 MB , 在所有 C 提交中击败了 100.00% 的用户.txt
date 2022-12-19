### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * tmp = head;

    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            tmp->next = l1;
            l1 = l1->next;
        }
        else{
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }

    if(l1 == NULL){
        tmp->next = l2;
    }
    else{
        tmp->next = l1;
    }

    return head->next;
}
// 1. merge list one by one 
/*
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i;
    struct ListNode * tmp = NULL;

    if((listsSize == 0) || (lists == NULL)){
        return NULL;
    }
    //if(listsSize == 1){
    //    return lists[0];
    //}
    for(i = 0; i < listsSize; ++ i){
        tmp = mergeTwoLists(tmp, lists[i]);
    }
    return tmp;
}
*/

// 2. Divide and conquer
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i;
    int gap = 1;
    int num = listsSize;
    struct ListNode * tmp =  NULL;
    
    if((listsSize == 0) || (lists == NULL)){
        return NULL;
    }

    while(num > 1){        
        gap *= 2;
        for(i = 0; i < listsSize; i += gap ){
            if((i + gap/2) < listsSize){
                lists[i] = mergeTwoLists(lists[i], lists[i + gap/2]);
            }            
        }
        num = num - num/2;
    }
    return lists[0];
}

```