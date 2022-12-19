```
void sortColors(int* nums, int numsSize){
    int count[3] = {0,0,0};
    for(int i = 0; i < numsSize; ++i)   ++count[nums[i]];
    for (int j=0; j < 3; ++j)
        for(int i=0; i < count[j]; ++i) *nums++ = j;
}
```
