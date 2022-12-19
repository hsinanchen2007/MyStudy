### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct node{
    int val;
    int num;
    struct node *next;
} node;
bool containsDuplicate(int* nums, int numsSize){
    node a[19],*p;
    int i;
    for(i=0;i<19;i++)
        a[i].next=NULL;
    for(i=0;i<numsSize;i++)
    {
        p=a[nums[i]%10+9].next;
        while(p)
            if(p->val==nums[i])
            {
                p->num++;
                break;
            }
            else
                p=p->next;
        if(!p)
        {
            p=(node *)malloc(sizeof(node));
            p->val=nums[i];
            p->num=1;
            p->next=a[nums[i]%10+9].next;
            a[nums[i]%10+9].next=p;
        }
    }
    for(i=0;i<19;i++)
    {
        p=a[i].next;
        while(p)
        {
            printf("%d ",p->val);
            if(p->num>=2)
                return true;
            else
                p=p->next;
        }
    }
    return false;
}
```