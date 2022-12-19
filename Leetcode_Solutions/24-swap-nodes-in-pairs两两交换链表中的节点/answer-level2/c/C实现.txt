### 解题思路
此处撰写解题思路

每次处理 ptr0-->ptr1-->ptr2　这样一个链表，swap(ptr0, ptr1, ptr2)交换ptr1, ptr2，使新的链表返回：　ptr0-->ptr2-->ptr1;
然后将ptr0前移，指向下一个要交换的链表,重新构成ptr0-->ptr1-->ptr2重复;


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* Swap( struct ListNode* prev, struct ListNode* l1, 
                       struct ListNode* l2)
{
    struct ListNode *TmpPtr;
   
    TmpPtr= l2->next; 
    
    prev->next=l2;
    l2->next=l1;
    l1->next=TmpPtr;

    return prev;
}


struct ListNode* swapPairs(struct ListNode* head){

     struct ListNode *prehead, *ptr0, *ptr1;
     prehead= malloc(sizeof( struct ListNode));

     prehead->next=head;
     ptr0=prehead;
     ptr1=prehead->next;
     if( ptr1 == NULL)
     {
         printf("Error:NULL pointer");
         return prehead->next;
     }

     while( (ptr1->next)!= NULL)
     {
         Swap(ptr0, ptr1, ptr1->next);  //交换前指向：　[ptr0, ptr1, ptr2(=ptr->next)]
                                        //交换后：　　　[ptr0, ptr2, ptr1]
         ptr0=ptr1;                     //ptr0指向下一个
         if(ptr0->next == NULL ){
             return prehead->next;
         }else{
             ptr1= ptr0->next;
         }
         
     }

     return prehead->next;



}
```