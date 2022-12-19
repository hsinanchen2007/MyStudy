//快排
```
int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int majorityElement(int* nums, int numsSize){

int res=0;
qsort(nums,numsSize,sizeof(nums[0]),cmp);
int cur_size=0,max_size=0;
int prev=nums[0];

for(int i=0;i<numsSize;i++)
{
    if(prev==nums[i])
      cur_size++;
    else 
    {
      prev=nums[i];
      cur_size=1;
    }

    if(cur_size==max_size)
      res=prev;
    else if(cur_size>max_size)
    {
        max_size=cur_size;
        res=prev;
    }
}
return res;
}

```
//摩尔投票法
```
int majorityElement(int* nums, int numsSize){
    int flag=nums[0];
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        if(count==0)
        {
            flag=nums[i];
            count++;
        }
        else if(nums[i]!=flag)
        {
            count--;
        }
        else
            count++;
    }
    return flag;
}
```
//哈希
```
struct node {
    int val;
    int num;
    UT_hash_handle hh;
};
struct node *map;

int cmp(struct node *a, struct node *b) {
    return b->num - a->num;
}
void printMap() {
    struct node* s;
    struct node* next;
    s = map;
    while (s != NULL) {
        next = s->hh.next;
        HASH_DEL(map, s);
        free(s);
        s = next;
    }
}

int majorityElement(int* nums, int numsSize){
    map = NULL;
    int val;
    if (nums == NULL) 
        return 0;
    struct node *tmp;
    int i;
    for (i = 0; i < numsSize; i++) {
        val = nums[i];
        HASH_FIND_INT(map, &val, tmp);
        if (tmp != NULL) 
            tmp->num++;
        else {
            tmp = malloc(sizeof(*tmp));
            tmp->val = nums[i];
            tmp->num = 1;
            HASH_ADD_INT(map, val, tmp);
        }
    }
    HASH_SORT(map, cmp);
    val = map->val;
    printMap();

    return val;
}
```
