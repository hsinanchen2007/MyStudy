click here

```
int pivotIndex(int* nums, int numsSize){
  
  int pivot = 0;
  int preSum = 0;
  int sum = 0;
  
  for(int i = 0; i < numsSize; i++)
  {
    sum += nums[i];
  }
  
  while(pivot < numsSize)
  {
    int postSum = sum - preSum - nums[pivot];

    if(preSum != postSum)
    {
      preSum += nums[pivot++];
    }
    else 
    { // preSum == postSum
      return pivot;
    }
  }

  return -1;
}
```
