```
/* 思路：
二分, 注意边界
*/

int search(int* nums, int numsSize, int target){
    int mid = 0;
    int start = 0;
    int end = numsSize - 1;

    while(mid >= start && mid <= end){
        if(target > nums[mid]){    start = mid + 1; }
        if(target < nums[mid]){    end = mid - 1;   }
        if(target == nums[mid]){   return mid;      }
        
        mid = (end - start) / 2 + start;
    }

    return -1;
}
```

