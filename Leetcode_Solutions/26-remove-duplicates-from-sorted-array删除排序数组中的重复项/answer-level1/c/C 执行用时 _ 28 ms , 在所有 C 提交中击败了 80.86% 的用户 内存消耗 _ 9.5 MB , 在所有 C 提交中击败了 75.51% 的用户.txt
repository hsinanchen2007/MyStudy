```
int removeDuplicates(int* nums, int numsSize){
    int putIndex = 0;
    int probeIndex = 0;
    int tmpIndex = 0;
    while(probeIndex < numsSize) {
        while (probeIndex < numsSize && nums[tmpIndex] == nums[probeIndex]) {
            probeIndex++;
        }
        nums[putIndex] = nums[probeIndex - 1];
        tmpIndex = probeIndex;
        putIndex++;
    }
    return putIndex;
}

```
