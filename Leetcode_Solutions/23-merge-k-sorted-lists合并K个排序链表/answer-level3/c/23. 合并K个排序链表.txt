### 解题思路
此处撰写解题思路
**p指针时要考虑各种情况如【】,这是要先判断再赋值要不然容易出错。head=lists[0].

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
    struct ListNode *head,*p;
    head=NULL;
    p=head;
    int x=0;
    while(l1&&l2){
        x++;
        if(l1->val<l2->val){
            if(x==1){
                head=l1;
                p=head;

            }else{
                head->next=l1;
                head=l1;
            }
            l1=l1->next;
        }
        else{
             if(x==1){
                head=l2;
                p=head;

            }
            else{
                head->next=l2;
                head=l2;
            }
            l2=l2->next;
        }
        
    }

while(l1){
    if(x!=0){
    head->next=l1;
    head=l1;
    l1=l1->next;
    }
    else{
        head=l1;
        p=head;
        break;
    }
    
}
while(l2){
    if(x!=0){
    head->next=l2;
    head=l2;
    l2=l2->next;
    }
    else{
        head=l2;
        p=head;
        break;
    }
   
}
return p;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *head,*p,*head1;
    head=NULL;
    p=head;
    
  if(listsSize==0)return NULL;
    if(listsSize==1)return lists[0];
    head=lists[0];
    //printf("%d",head->val);
    for(int i=1;i<listsSize;i++){

        
        p=mergeTwoLists(head,lists[i]);
        head=p;

        

    }
    return head;

}
```