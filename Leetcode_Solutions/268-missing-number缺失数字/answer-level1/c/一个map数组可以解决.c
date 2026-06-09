```
int missingNumber(int* nums, int numsSize){
    int i;
    int map[10001] = {0};
    for (i = 0; i < numsSize; i++) {
        map[nums[i]] = 1;
    }
    for (i = 0; i < numsSize; i++) {
        if (map[i] == 0)
            break;
    } 
    return i;
}
```
