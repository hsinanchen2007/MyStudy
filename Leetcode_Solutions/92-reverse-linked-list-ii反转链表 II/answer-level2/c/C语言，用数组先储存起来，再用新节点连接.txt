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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int i=0;
    struct ListNode*nownode=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*tmp1=(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp1=NULL;
    nownode=head;
    int *num;
    num=(int*)malloc(sizeof(int)*(n-m+1));
    for(i=1;i<m;i++)
    {
        tmp1=nownode;
        nownode=nownode->next;
    }
    int k=0;
    for(i=m;m<=n;m++)
    {
        num[k]=nownode->val;
        k++;
        nownode=nownode->next;
    }
     struct ListNode*outputnode=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*nownode1=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(tmp1==NULL)
    {
        int m=0;
        for(i=k-1;i>=0;i--)
        {
            if(m==0)
            {
              
               outputnode->val=num[i];
               outputnode->next=NULL;
               nownode1=outputnode;
               m++;
            }
            else if(m==1)
            {
                struct ListNode*newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
                newnode->val=num[i];
                newnode->next=NULL;
                nownode1->next=newnode;
                nownode1=newnode;
            }

        }
        nownode1->next=nownode;
        return outputnode;
    }
    if(tmp1!=NULL)
    {
        for(i=k-1;i>=0;i--)
        {
                struct ListNode*newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
                newnode->val=num[i];
                newnode->next=NULL;
                tmp1->next=newnode;
                tmp1=newnode;
        }
        tmp1->next=nownode;
        return head;
    }

        return 1;
}
```