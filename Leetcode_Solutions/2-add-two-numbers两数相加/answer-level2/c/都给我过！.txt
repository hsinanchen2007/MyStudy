### 解题思路
就是最普通不过的思路：直接相加
需要注意的就是链表长度不一样的时候的两种处理办法以及最后需要进位时要开辟空间

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1,*p2,*prep;
    int mid_val=0,mid_sum=0;
    p1=l1;
    p2=l2;
    while(p1&&p2){
        mid_sum=mid_val+p1->val+p2->val;
        if(mid_sum>9){
            p1->val=mid_sum-10;
            mid_val=1;
        }
        else{
            p1->val=mid_val+p1->val+p2->val;
            mid_val=0;
        }
        prep=p1;
        p1=p1->next;
        p2=p2->next;
    }
    if(p1==NULL&&p2!=NULL){
        if(mid_val==0)
            prep->next=p2;
        else {
            prep->next=p2;
            while(p2){
                mid_sum=p2->val+mid_val;
                if(mid_sum>9){
                    p2->val=mid_sum-10;
                    mid_val=1;
                }
                else {
                    p2->val=mid_sum;
                    mid_val=0;
                }
                prep=p2;
                p2=p2->next;
            }
            

        }
    }
    else if(p2==NULL&&p1!=NULL){
        if(mid_val==0)
            prep->next=p1;
        else {
            prep->next=p1;
            while(p1){
                mid_sum=p1->val+mid_val;
                if(mid_sum>9){
                    p1->val=mid_sum-10;
                    mid_val=1;
                }
                else {
                    p1->val=mid_sum;
                    mid_val=0;
                }
                prep=p1;
                p1=p1->next;
            }
            

        }
    }
    if(mid_val!=0){
        prep->next=(struct ListNode*)malloc(sizeof(struct ListNode));;
        prep->next->val=1;
        prep->next->next=NULL;
    }
    return l1;
}
```