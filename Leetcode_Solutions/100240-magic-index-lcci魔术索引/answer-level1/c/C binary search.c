```
int binarySearch(int *nums, int left, int right)
{
  if(left > right) return -1;

  int mid = (left + right) >> 1;

  if(mid == nums[mid]) return mid;

  int ret = binarySearch(nums, left, mid - 1);

  return ret == -1 ? binarySearch(nums, mid + 1, right) : ret;
}

int findMagicIndex(int* nums, int numsSize)
{
  return binarySearch(nums, 0, numsSize - 1);
}
```
