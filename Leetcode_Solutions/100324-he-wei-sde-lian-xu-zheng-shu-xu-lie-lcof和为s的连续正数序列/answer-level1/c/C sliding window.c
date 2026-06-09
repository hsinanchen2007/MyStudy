```
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){

  *returnSize = 0;

  if(target < 3) return NULL;

  #define MAX_LEN (target / 2)

  int **ret = malloc(sizeof(int *) * MAX_LEN);
  *returnColumnSizes = malloc(sizeof(int) * MAX_LEN);
  memset(*returnColumnSizes, 0, sizeof(int) * MAX_LEN);

  int left = 1;
  int right = 2;
  int sum = left + right;

  while(right <= MAX_LEN + 1)
  {
    if(sum == target)
    {
      int retIndex = (*returnSize)++;
      int len = right - left + 1;
      assert(len >= 2);

      ret[retIndex] = malloc(sizeof(int) * len);
      (*returnColumnSizes)[retIndex] = len;

      for(int i = left; i <= right; i++)
        ret[retIndex][i - left] = i;

      sum -= left++;
    }
    else if(sum < target)
    {
      right++;
      sum += right;
    }
    else // sum > target
    { 
      sum -= left++;
    }
  }

  return ret;
}
```
