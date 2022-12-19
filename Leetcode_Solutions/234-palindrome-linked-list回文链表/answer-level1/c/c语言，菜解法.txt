### 解题思路
未按照要求，建立了一个辅助数组，比较容易想到的

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    int len=0,i=0;
    int j;
    int *help;
    int flag=0;
    struct ListNode *p;
    if(head==NULL){
        return true;
    }
    p=head;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    if(len==1){
        return true;
    }
    help=(int *)malloc(sizeof(int)*len);
    p=head;
    while(p!=NULL){
        help[i++]=p->val;
        p=p->next;
    }
    for(i=0,j=len-1;i<j;i++,j--){
        if(help[i]!=help[j]){
            flag=1;
        }
    }
    if(flag==1){
        return false;
    }
    return true;
}
```