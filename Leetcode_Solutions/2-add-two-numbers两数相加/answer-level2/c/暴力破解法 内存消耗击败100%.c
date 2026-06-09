### 解题思路
此题较简单，主要是不要弄混了进位相加的顺序

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
    int a[10000]={0},b[10000]={0},c[10000]={0};
    int p,i=0,j=0,k;
    while(l1){
        a[i++]=l1->val;
        l1=l1->next;
    }
    while(l2){
        b[j++]=l2->val;
        l2=l2->next;
    }
    int max=i>j?i:j;
    int flag=0;
    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next=NULL;
    for(k=0;k<max;k++){
        if(a[k]+b[k]>=10){
            c[k]=a[k]+b[k]-10+flag;
            flag=1;
        }
        else{
            if(a[k]+b[k]+flag>=10){
                c[k]=a[k]+b[k]+flag-10;
                flag=1;   
            }
            else{
                c[k]=a[k]+b[k]+flag;
                flag=0;
            }
            
        }
        
    }
    if(flag==1)
        c[max]=flag;
    
    struct ListNode *ret = l3;
    for(k=0;k<=max;k++){
        l3->next=(struct ListNode*)calloc(1,sizeof(struct ListNode));
        l3=l3->next;
        if(c[max]==0&&k==max-1){
            l3->val=c[k];
            l3->next=NULL;
            break;
        }
            
        l3->val=c[k];
        l3->next=NULL;

    }
    return ret->next;
}
```