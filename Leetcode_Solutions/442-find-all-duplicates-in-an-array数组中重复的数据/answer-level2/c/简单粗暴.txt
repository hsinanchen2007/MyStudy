### 解题思路
先排序再进行前后匹配

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare(const void *a, const void *b){
     return *(int *)a-*(int *)b;
 }
int* findDuplicates(int* nums, int numsSize, int* returnSize){
  qsort(nums, numsSize, sizeof(int), compare);
  int i, cnt=0;
  int* ans=(int*)malloc(sizeof(int)*100000);
  for(i=0;i<numsSize-1;i++){
      if(nums[i]==nums[i+1]){
          i++;
          ans[cnt++]=nums[i];
      }
  }
  *returnSize=cnt;
  return ans;
}
```