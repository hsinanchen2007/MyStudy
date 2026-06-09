### 解题思路
此处撰写解题思路
时间复杂度为O（n）[创建哈希链表]+O(n)[遍历得到出现次数最多的元素]=O（n）,时间打败C95%，内存100%






### 代码

```c
#define size 197
typedef struct HashNode_{
    int val;
    int number;
    struct HashNode_ *next;
}HashNode;

typedef struct HashRow_{
    HashNode *head;
}HashRow;

HashRow *row;

HashRow* InitialCreat(){
    HashRow *p=(HashRow*)calloc(size,sizeof(HashRow));
    return p;
}

int getpos(int target)
{
    int m=0;
    if(target>0) return target%size;
    else
     {
         m=target/size;
         target=target-m*size;
         target+=size;
         return getpos(target);
     }
}

bool SearchHash(int target){
    int pos=getpos(target);
    HashNode *p;
    if(row[pos].head==NULL) //empety 
        return false;
    else
        p=row[pos].head;
    while(p!=NULL)
    {
        if(p->val==target) return true;
        p=p->next;
    }
    return false;
}


void In_add(int target){
    int pos=getpos(target);
    if(SearchHash(target)==false)
    {
        HashNode *p=(HashNode*)calloc(1,sizeof(HashNode));
        p->val=target;
        p->number=1;
        if(row[pos].head==NULL) 
            p->next=NULL;
        else
            p->next=row[pos].head;
        row[pos].head=p;
    }
    else
    {
        HashNode *p=row[pos].head;
        while(p!=NULL)
        {
            if(p->val==target) 
            {
                p->number+=1;
                break;
            }
        }
    }
}


int majorityElement(int* nums, int numsSize){
    row=InitialCreat();
    HashNode *node;
    HashNode *maxSizeNode;
    int maxSize=0;
    for(int i=0;i<numsSize;i++)
    {
        In_add(nums[i]);
    }
    for(int i=0;i<size;i++)
    {
        if(row[i].head!=NULL)
        {
            node=row[i].head;
            while(node!=NULL)
            {
                printf("i:%d \n",i);
                printf("node->val:%d ",node->val);
                printf("node->number:%d \n",node->number);
                if(node->number>maxSize)
                {
                    maxSizeNode=node;
                    maxSize=node->number;
                }
                     
                node=node->next;
            }
        }
    }
    return maxSizeNode->val;
}







```