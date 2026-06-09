### 解题思路
此处撰写解题思路

复杂度可能不满足要求。

```c

typedef struct _my_struct {
    long id;                    
    char name[10];
    UT_hash_handle hh;
}my_struct;

my_struct *g_hash = NULL;


long cmp(my_struct *a, my_struct *b) {
    return (b->id - a->id);
}


int thirdMax(int* nums, int numsSize){

for(int i = 0; i < numsSize;i++) {
    my_struct *find = 0;
    HASH_FIND_INT(g_hash,&nums[i],find);
    if(find == 0) {
        find = malloc(sizeof(my_struct));
        find->id = nums[i];
        HASH_ADD_INT(g_hash,id,find);
    }
}
HASH_SORT(g_hash,cmp);

int cnt = HASH_COUNT(g_hash);
my_struct *current_user, *tmpuseless;
HASH_ITER(hh, g_hash, current_user, tmpuseless) {
   printf("%d %d\r\n", current_user->id,cnt);
}

if(cnt < 3)
{
    cnt = 1;
}
else
{
    cnt = 3;
}
int k = 1;
long value;

HASH_ITER(hh, g_hash, current_user, tmpuseless) {
    if(k == cnt) {
        value = current_user->id;
        break;
    }
    k++;
}

HASH_ITER(hh, g_hash, current_user, tmpuseless) {
    HASH_DEL(g_hash,current_user); 
    free(current_user); 
}
return value;
}
```