/*
// divide and conquer
int majorityElement(int* nums, int numsSize){

  if(numsSize == 1) return *nums;

  // divid
  int *left = nums;
  int leftSize = numsSize >> 1;

  int *right = nums + leftSize;
  int rightSize = numsSize - leftSize;

  // conquer
  int leftMajor = majorityElement(left, leftSize);
  int righMajor = majorityElement(right, rightSize);

  // merge
  if(leftMajor == righMajor) return leftMajor;
  else
  {
    int leftMajorCnt = 0, righMajorCnt = 0;

    for(int i = 0; i < numsSize; i++)
    {
      if(nums[i] == leftMajor) leftMajorCnt++;
      else if(nums[i] == righMajor) righMajorCnt++;
    }

    return leftMajorCnt > righMajorCnt ? leftMajor : righMajor;
  }
}
*/

// Boyer-Moore Algorithm
int majorityElement(int* nums, int numsSize){

  int candidate;
  int cadidateCnt = 0;

  for(int i = 0; i < numsSize; i++)
  {
    if(cadidateCnt == 0)
    {
      candidate = nums[i];
      cadidateCnt++;
    }
    else
    {
      if(nums[i] == candidate) cadidateCnt++;
      else cadidateCnt--;
    }
  }

  return candidate;
}

```
