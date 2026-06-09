**求和**
```c
int missingNumber(int* nums, int numsSize){
    int ans = (numsSize + 1) * numsSize / 2, i;
    for(i = 0; i < numsSize; i++){
        ans -= nums[i];
    }
    return ans;
}
```
**异或**
```c
int missingNumber(int* nums, int numsSize){
    int ans = numsSize, i;
    for(i = 0; i < numsSize; i++){
        ans ^= i ^ nums[i];
    }
    return ans;
}
```
**哈希**
```c
int missingNumber(int* nums, int numsSize){
    int *p = (int*)calloc(numsSize + 1, sizeof(int));
    int i;
    for(i = 0; i < numsSize; i++){
        p[nums[i]] = 1;
    }
    for(i = 0; i <= numsSize; i++){
        if(p[i] == 0)
            return i;
    }
    return -1; //not found
}
```