一般c语言没有很好的库函数，遇到插入删除这种事想想链表
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct lianbiao
{
    int val;
    struct lianbiao*next;
};
typedef struct lianbiao node;
node*a;
node*p;
node*pre;
void insert(int value,int wz)
{
    int i;
    for(i=0;i<wz;i++)
    {
        if(p==NULL)
        {
            break;
        }
        p=p->next;
        pre=pre->next;
    }
    p=(node*)malloc(sizeof(node));
    p->val=value;
    p->next=pre->next;
    pre->next=p;
}
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int*tar=(int*)malloc(sizeof(int)*indexSize);
a=(node*)malloc(sizeof(node));
a->next=NULL;
p=a->next;
pre=a;
int i;
for(i=0;i<indexSize;i++)
{
    p=a->next;
    pre=a;
    insert(nums[i],index[i]);
}
p=a->next;
for(i=0;i<indexSize;i++)
{
    tar[i]=p->val;
    p=p->next;
}
*returnSize=indexSize;
return tar;
}
```

