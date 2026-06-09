一趟循环解决
```
int minPatches(int* nums, int numsSize, int n){
    long int sum = 0;
    int i = 0;
    int j = 1;
    int count = 0;
    while( j <= n){
        if( i < numsSize &&  sum >= nums[i] - 1){
            sum += nums[i];
            i++;
            continue;
        }
        if(sum >= j){
            j = sum + 1;
            continue;
        }
        if(sum < j){
            sum += j;
            printf("%d", sum);
            j++;
            count++;
        }
    }
    return count;
}
```
