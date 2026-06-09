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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int length(struct ListNode* head){
     int len=0;
     while(head){
         head=head->next;
         len++;
     }
     return len;
 }
int* nextLargerNodes(struct ListNode* head, int* returnSize){

    struct ListNode* p=head;
    int len=length(head);
    int i=0;
    int* res=(int*)malloc(sizeof(int)*len);
    while(i<len){
        struct ListNode* q=p->next;
        while(q&&q->val<=p->val){
            q=q->next;
        }
        if(q){
            res[i++]=q->val;
        }
        else{
            res[i++]=0;
        }
        p=p->next;
    }
    *returnSize=len;
    return res;
}
```