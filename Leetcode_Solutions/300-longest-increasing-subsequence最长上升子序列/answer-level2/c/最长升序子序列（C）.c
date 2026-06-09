```
int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
   int i = 0;
   int end = 0;
   int *MLS = (int *)calloc(sizeof(int), numsSize);
   int left;
   int right;
   int mid;
   MLS[0] = nums[0];
   for (i = 1; i < numsSize; i++) {
        left = 0;
        right = end;
        while (left < right) {
            mid = (left + right)/2;
            if (MLS[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (MLS[left] < nums[i]) {
            MLS[++end] = nums[i];
        } else {
            MLS[left] = nums[i];
        }
   }
   
   return end+1;
}
```
