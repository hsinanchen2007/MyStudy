### 解题思路
Hash表的简单应用。

### 代码

```c
#define max(a, b) a > b ? a : b

#define min(a, b) a < b ? a : b

typedef struct _my_struct {
  int id;
  int sum;
  int position;
  UT_hash_handle hh; /* makes this structure hashable */
} my_struct;

my_struct *g_hash = NULL;

// 求每个位置累加和
// 如果累加和为0，则位置保存起来。
// 如果累加和相同，把最大的和最小的位置保存起来。

// 求差值。
//-1,1,-1,1,-1,1
int cmp(my_struct *a, my_struct *b) { return (b->sum - a->sum); }

int findMaxLength(int *nums, int numsSize) {

  if (numsSize == 0 || nums == 0) {
    return 0;
  }
  int sum[numsSize];

  for (int i = 0; i < numsSize; i++) {
    if(nums[i] ==0) nums[i] = -1;
    sum[i] = 0;
  }
  sum[0] = nums[0];
  for (int i = 1; i < numsSize; i++) {
    sum[i] = sum[i-1] + nums[i];
  }

  my_struct *find = 0;

  for (int i = 0; i < numsSize; i++) {

    HASH_FIND_INT(g_hash, &sum[i], find);

    if (find == 0) {
      find = malloc(sizeof(my_struct));
      find->id = sum[i];
      find->position = i;
      if(sum[i] == 0)
      {
         find->sum = i+1;
      }
      else{
          find->sum = 0;
      }
      HASH_ADD_INT(g_hash, id, find);
      

    } else {
       if(sum[i] == 0)
       {
          find->sum = i+1;
       }
       else {
           find->sum = max(abs(i - find->position), find->sum);
       }
    }
  }

  HASH_SORT(g_hash, cmp);

  int k = 0;
  int value = 0;
  my_struct *current_user, *tmpuseless;

  HASH_ITER(hh, g_hash, current_user, tmpuseless) {
    if (k == 0) {
      value = current_user->sum;
      k = 1;
    }
    HASH_DEL(g_hash, current_user);
    free(current_user);
  }

  return value;
}
```