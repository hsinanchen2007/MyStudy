乘积大于等于k时l右移，小于k时r右移，同时记录以不超过l为开头，以r为结尾的子序列个数。
```
#define MAX_SIZE 50001
int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int l = 0; 
    int r = 0;
    int res = 0;
    if (numsSize == 0 || k <= 1) {
        return 0;
    }
    int sum = nums[0];
    while (l < numsSize) {
        while (sum < k) {
            res += r - l + 1;
            r++;
            if (r == numsSize) {
                return res;
            }
            sum *= nums[r];
        }  
        sum /= nums[l];
        l++;
    }
    return res;
}
```
