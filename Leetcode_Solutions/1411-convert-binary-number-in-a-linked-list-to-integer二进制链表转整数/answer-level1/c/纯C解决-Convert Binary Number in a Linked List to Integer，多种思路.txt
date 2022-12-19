### 解题思路
这里给了存储法和递归法

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//存储法
int getLength(struct ListNode* head)
{
    int length=0;
    while(head)
    {
        head=head->next;
        length++;
    }
    return length;
}
int getDecimalValue(struct ListNode* head){
    int length=getLength(head);
    int num[length];
    int i=0,base=1,result=0;
    while(head)
    {
        num[i++]=head->val;
        head=head->next;
    }
    for(i=i-1;i>=0;i--)
    {
        result+=base*num[i];
        base*=2;
    }
    return result;
}


```

```c
//递归
void Translation(struct ListNode *head,int *result,int *base)
{
    if(!head)
        return ;
    Translation(head->next,result,base);
    *result+=(head->val)*(*base);
    (*base)*=2;//提供给上一级使用
}
int getDecimalValue(struct ListNode* head){
    int result=0;
    int base=1;
    Translation(head,&result,&base);
    return result;
}
```
