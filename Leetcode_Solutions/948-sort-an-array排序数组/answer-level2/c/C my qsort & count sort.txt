click here to view

```

void swap(int *nums, int index1, int index2)
{
  if(index1 == index2) return;

  int tmp = nums[index1];
  nums[index1] = nums[index2];
  nums[index2] = tmp;
}

void myQsort(int *nums, int start, int end)
{
  if(start >= end) return;

  int left = start;
  int right = end;

  int target = nums[start];

  while(left <= right)
  {
    if(nums[left] <= target)
    {
      left++;
    }
    else
    {
      swap(nums, left, right--);
    }
  }

  int targetPos = right;

  swap(nums, start, targetPos);

  myQsort(nums, start, targetPos - 1);
  myQsort(nums, targetPos + 1, end);
}

#define OFFSET  50000
#define MAP_LEN (OFFSET * 2 + 1)

void myCntSort(int* nums, int numsSize)
{
  int map[MAP_LEN]= {0};

  for(int i = 0; i < numsSize; i++)
  {
    map[nums[i] + OFFSET]++;
  }

  int index = 0;

  for(int i = 0; i < MAP_LEN; i++)
  {
    if(map[i])
    {
      int cnt = map[i];

      while(cnt--)
      {
        nums[index++] = i - OFFSET;
      }
    }
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){

  *returnSize = numsSize;

  //myQsort(nums, 0, numsSize - 1);

  myCntSort(nums, numsSize);

  return nums;
}


```
